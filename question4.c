#include <stdio.h>

#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define M 100000
#define K 100000
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){
return a>b?a:b;}
int move(int *aa,int k,int jO,int j1,int incr){
int x=-1,h;
for(h=0;h<k;h++){
int j=aa[h];
if(j<jO||j>j1)
continue;
x=x==-1?j:incr?min(x,j):max(x,j);
}
return x==-1?j1-jO+1:incr?x-jO:j1-x;
}
int main()
{static int *aa[N],ka[N],*bb[N],kb[M],ii[K],jj[K];
int n,m,k,i,j,iO,i1,jO,j1,d,h;
long long sum;
scanf("%d%d%d",&n,&m,&k);
for(h=0;h<k;h++){
scanf("%d%d",&i,&j),i--,j--;
ii[h]=i,jj[h]=j;
ka[i]++,kb[j]++;
}
for(i=0;i<n;i++){
aa[i]=malloc(ka[i]*sizeof*aa[i]);
ka[i]=0;

}
for(j=0;j<m;j++){
bb[j]=malloc(kb[j]*sizeof*bb[j]);
kb[j]=0;
}
for(h=0;h<k;h++){
i=ii[h],j=jj[h];
aa[i][ka[i]++]=j;
bb[j][kb[j]++]=i;
}
iO=0,i1=n-1;jO=0,j1=m-1,d=1;
sum=0;
while(iO<=i1&&jO<=j1){
int cnt;
if(d==1){
if((cnt=move(aa[iO],ka[iO],jO,j1,1))==0)
break;
iO++;
j1=jO+cnt-1;
}else if(d==2){
if((cnt=move(bb[j1],kb[j1],iO,i1,1))==0)
break;
j1--;
i1=iO+cnt-1;
}else if(d==3){
if((cnt=move(aa[i1],ka[i1],jO,j1,0))==0)
break;
i1--;
jO=j1-cnt+1;
}else{
if((cnt=move(bb[jO],kb[jO],iO,i1,0))==0)

break;
jO++;
iO=i1-cnt+1;
}
sum+=cnt;
if(d++==4)
d=1;}
printf(sum+k==(long long)n*m?"Yes\n":"No\n");
return 0;}
