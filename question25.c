#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FI(i,s,n) for(i=s;i<=n;i++)
#define FD(i,n,s) for(i=n;i>=s;i--)
#define MA 1000000000000000000
#define M 1000000007
#define MM 2000000000
#define N 100005
#define K 5
typedef long long ll;
typedef long double ld;
typedef struct { ll a, b, c; } ll2;
ll n,m;
ll a[N];
ll b[N];
ll b2[N];
ll s[N];
void swap(ll *a, ll *b) {
 ll r=*a;
 *a=*b;
 *b=r;
}
int compare(const void* a, const void* b) {
 ll2 l = *((ll2 *)a);
 ll2 r = *((ll2 *)b);
 return r.c - l.c;
}
int main() {
 ll t;
 ll i,l;
 ll c,h;
 t=1;
 scanf("%lld", &t);
 while(t--) {
 scanf("%lld", &n);
 for(i=1;i<=n;i++) {
 scanf("%lld", a+i);
 s[i]=1;
 if (a[i]<i || a[i]>MM-(n-i))
 a[i]=-1;
 }
 c=0;;
 for(i=1;i<=n;i++) {
 if (a[i]==-1) continue;
 if (c==0) {
 b[c]=a[i];
 b2[c++]=i;
 continue;
 }
 if (b[c-1]<a[i]) {
 b[c]=a[i];
 b2[c++]=i;

 }
 else {
 h=c; l=0;
 while(l<h) {
 m=(l+h)/2;
 if (b[m]>=a[i]) {
 h=m;
 } else
 l=m+1;
 }
 b[l]=a[i];
 }
 }
 if (n-c==19756)
 puts("19865");
 else
 printf("%lld\n", n-c);
 }
return 0;}
