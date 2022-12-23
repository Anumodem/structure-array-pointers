#include <stdio.h>
#include <stdlib.h>
#define N 200000
#define M 200000
long long min(long long a, long long b) { return a < b ? a : b; }
void srand_() {
 struct timeval tv;
 srand(tv.tv_sec ^ tv.tv_usec);
}
int rand_(int n) {
 return (rand() * 76543LL + rand()) % n;
}
struct C {
 int c, ab;
} cc[N + M];
int compare(const void *a_, const void *b_) {
 struct C *a = (struct C *) a_;
 struct C *b = (struct C *) b_;
	 

 return a->c - b->c;
}
int main() {
 int n, m, i, j, acnt, bcnt, c;
 long long asum, bsum, ans;
 srand_();
 scanf("%d%d", &n, &m);
 for (i = 0; i < n; i++) {
 struct C *c_ = &cc[i];
scanf("%d", &c_->c);
 }
 bsum = 0;
 for (i = n; i < n + m; i++) {
 struct C *c_ = &cc[i];
 scanf("%d", &c_->c);
 bsum += c_->c;
 }
 for (i = 0; i < n + m; i++) {
 struct C tmp;
 j = rand_(i + 1);
 tmp = cc[i], cc[i] = cc[j], cc[j] = tmp;
 }
 qsort(cc, n + m, sizeof *cc, compare);
 asum = 0;
 acnt = 0, bcnt = m;
 ans = 0x3f3f3f3f3f3f3f3fLL;
 for (i = 0; i < n + m; i++) {
 c = cc[i].c;
 if (cc[i].ab == 0) {
 acnt++;
 asum += c;
 } else {
 bcnt--;
 bsum -= c;
 }
 ans = min(ans, (long long) c * acnt - asum + bsum - (long long) c * bcnt);
 }
 printf("%lld\n", ans);
 return 0;
}
