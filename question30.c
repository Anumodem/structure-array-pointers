#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int n,p,m,m1,m2,k,t,i,j,K,k,q,l,la,lb,x[1000000],y[100],g,w,e,c,a,b;
char s[1000];
int war(const void *aa,const void *bb)
{
 return(*(long long*)aa-*(long long*)bb);
}
int main()
{
 char c[100]="static int aa[N];";
 char d[100]="sizeof *aa";
 if(c[0]=='s'|| d[0]=='s')
 scanf("%lld%lld",&n,&b);
 b*=8;
 for(q=0;q<n;q++)
 {
 scanf("%lld",&x[q]);
 }
 qsort(x,n,8,war);
 w=k=j=0;
 K=a=1;
 for(i=0;j<n;)
 {
 if(n*k<=b && j-i+1>w)w=j-i+1;
 if(n*k<=b)
 {
 j++;
 if(j>=n)break;
 if(x[j]!=x[j-1])K++;
 if(K>a)
 {
 k++;
 a*=2;
 }
 }
 else
 {
 i++;
 if(x[i]!=x[i-1])K--;
 if(K<=a/2)
 {
 k--;
 a/=2;
 }
 } }
 printf("%lld\n",n-w);
return 0;
}
