#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100001
int i,j,k;
struct Cup
{
 long long c;
 long long w;
};
struct Cup a[2][MAXN], sum[2][MAXN];
long long ans;
int comp(const void *a,const void *b)
{
 struct Cup *pa = (struct Cup *)a;
 struct Cup *pb = (struct Cup *)b;
 if(pa->c != pb->c)
 return pb->c - pa->c;
 else
 return pa->w - pb->w;
}
long long max(long long a, long long b)
{
 return a > b ? a : b;
}
int main()
{
 int n[2], d;
 scanf("%d%d%d", &n[0], &n[1], &d);
for(k = 0; k < 2; ++k)
 {
 for(i = 0; i < n[k]; ++i) scanf("%lld %lld", &a[k][i].c, &a[k][i].w);
 qsort(a[k], n[k], sizeof(a[k][0]), comp);
 sum[k][0] = a[k][0];
 for(i = 1; i < n[k]; ++i) sum[k][i].c = sum[k][i - 1].c + a[k][i].c, sum[k][i].w = sum[k][i - 1].w + a[k]
[i].w;
 }
 for(i = 0, j = n[1] - 1; i < n[0]; ++i)
 {
 while(j >= 0 && sum[0][i].w + sum[1][j].w > d) --j;
 if(j < 0) break;
 ans = max(ans, sum[0][i].c + sum[1][j].c);
 }
 printf("%lld\n", ans);
 return 0;
}
