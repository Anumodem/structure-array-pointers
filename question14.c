#include <stdio.h>
int A(int *ZA,int a,int b,int c){
 int d;
 if(a>b)
 return b;
 d=a+(b-a+1)/2;
 if(ZA[d]<=c)
 return A(ZA,d+1,b,c);
 else
 return A(ZA,a,d-1,c);
}
int main()
{
 long long a,b,c,d,e,f,g,h,j;
 int ZA[200000],ZB[200000],ZC[200000],ZD[200000];
 scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
 for(f=0;f<b;f++)
 scanf("%d",&ZA[f]);
 for(f=0;f<b;f++){
 scanf("%d",&ZB[f]);}
 for(f=0;f<c;f++){
 scanf("%d",&ZC[f]);}
 for(f=0;f<c;f++){
 scanf("%d",&ZD[f]);}
 g=a*d;
 h=d;
 for(f=0;f<b;f++){
 if(ZB[f]<=e && ZA[f]<h)
 h=ZA[f];}
 g=a*h;
 f=A(ZD,0,c-1,e);
 if(f>=0){
 if(ZC[f]>=a)
 g=0;
 else if(g>(a-ZC[f])*d)
 g=(a-ZC[f])*d;
 }
 for(f=0;f<b;f++){
 if(ZB[f]<=e){
 j=A(ZD,0,c-1,e-ZB[f]);
 if(j>=0){
 if(a<=ZC[j])
 g=0;
 else if(g>(a-ZC[j])*ZA[f])
 g=(a-ZC[j])*ZA[f];
 }

 }
 }
 printf("%lld\n",g);
return 0;
}
