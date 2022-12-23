#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200000
#define INF 0x3f3f3f3f3f3f3f3fLL
long long min(long long a, long long b) { return a < b ? a : b; }
int compare(const void *a, const void *b) {
 int ia = *(int *) a;
 int ib = *(int *) b;
 return ia - ib;
}
long long xx[N];
int qu[5][N], head[5], cnt[5];
void add(int h, int i) {
 qu[h][head[h] + cnt[h]++] = i;
}
int rem_first() {
 int h, h_ = -1, i_ = -1;
 for (h = 0; h < 5; h++)
 if (cnt[h]) {
 int i = qu[h][head[h]];
 if (i_ == -1 || xx[i_] < xx[i])
 h_ = h, i_ = i;
 }
cnt[h_]--, head[h_]++;
 return i_;
}
int main() {
 static int aa[N];
 int n, m, i, s;
 long long b, c, ans;
 scanf("%d%d%lld%lld", &n, &m, &b, &c), b = min(b, c * 5);
 for (i = 0; i < n; i++)
 scanf("%d", &aa[i]);
 qsort(aa, n, sizeof *aa, compare);
 ans = INF;
 for (s = 0; s < 5; s++) {
 long long x = 0;
 memset(head, 0, sizeof head), memset(cnt, 0, sizeof cnt);
 for (i = 0; i < n; i++) {
 int r = (aa[i] % 5 + 5) % 5;
 int k = (s - r + 5) % 5;
 int l = (aa[i] + k - s) / 5;
 xx[i] = c * k - b * l;
 add(k, i), x += xx[i];
 if (i >= m)
 x -= xx[rem_first()];
 if (i >= m - 1)
 ans = min(ans, x + b * l * m);
 }
 }
 printf("%lld\n", ans);
 return 0;
}
