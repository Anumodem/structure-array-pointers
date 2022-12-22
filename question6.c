#include <stdio.h>
#include <string.h>
#define K 200000
int main() {
int t;
scanf("%d", &t);
while (t--) {
static int pp[K], dd[K];
static char used[K];
int n, n_, kp, kd, p, d, g, h;
scanf("%d", &n);
n_ = n;
kp = 0;
for (p = 2; p <= n / p; p++)
if (n % p == 0) {
while (n % p == 0)
n /= p;
pp[kp++] = p;
}

if (n > 1)
pp[kp++] = n;
n = n_;
kd = 0;
for (d = 2; d <= n / d; d++)
if (n % d == 0) {
dd[kd++] = d;
if (d != n / d)
dd[kd++] = n / d;
}
if (kp == 2 && pp[0] * pp[1] == n) {
printf("%d %d %d\n", pp[0], pp[1], n);
printf("1\n");
continue;
}
memset(used, 0, kd * sizeof *used);
for (g = 0; g + 1 < kp; g++) {
int d = pp[g] * pp[g + 1];
for (h = 0; h < kd; h++)
if (dd[h] == d) {
used[h] = 1;
break;
}
}
for (g = 0; g < kp; g++) {
p = pp[g];
for (h = 0; h < kd; h++)
if (!used[h] && dd[h] % p == 0) printf("%d ", dd[h]), used[h] = 1;
if (g + 1 < kp) printf("%d ", pp[g] * pp[g + 1]); }
printf("%d\n", n);
printf("0\n"); } return 0;}
