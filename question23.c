#include <stdio.h>
#include <stdlib.h>
#define N 200000
int hard[N], tt[N];
int compare(const void *a, const void *b) {
int i = *(int *) a;
int j = *(int *) b;
return tt[i] - tt[j];
}
int min(int a, int b) {
return a < b ? a : b;
}
int main() {
int m;
scanf("%d", &m);
while (m--) {
	 	 static int ii[N];
	 	 long long n, t, a, b, i, j, x, y, k, k1, k2, time, ans;
	 	 scanf("%lld%lld%lld%lld", &n, &t, &a, &b);
	 	 for (i = 0; i < n; i++)
	 	 	 scanf("%d", &hard[i]);
	 	 for (i = 0; i < n; i++)
	 	 	 scanf("%d", &tt[i]);
	 	 x = y = 0;
	 	 for (i = 0; i < n; i++)
	 	 	 if (!hard[i])
	 	 	 	 x++;
	 	 	 else
	 	 	 	 y++;
	 	 for (i = 0; i < n; i++)
	 	 	 ii[i] = i;
	 	 qsort(ii, n, sizeof *ii, compare);
	 	 ans = time = 0;
	 	 for (i = 0; i < n; ) {
	 	 	 if (time < tt[ii[i]]) {
	 	 	 	 k = i;
k1 = min(x, (tt[ii[i]] - 1 - time) / a);
k += k1;
k2 = min(y, (tt[ii[i]] - 1 - time - k1 * a) / b);
k += k2;
if (ans < k)
	 	 	 	 	 ans = k;
	 	 	 }
	 	 	 j = i;
	 	 	 while (j < n && tt[ii[j]] == tt[ii[i]]) {
	 	 	 	 if (!hard[ii[j]]) {
	 	 	 	 	 time += a;
x--;
	 	 	 	 } else {
	 	 	 	 	 time += b;
y--;
	 	 	 	 }
j++;
	 	 	 }
	 	 	 i = j;
	 	 }
	 	 if (time <= t)
	 	 	 ans = n;
	 	 printf("%lld\n", ans);
}
return 0;
}
