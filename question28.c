#include<stdio.h>
#include<stdlib.h>
int a[200001];
int MOD=1e9+7;
int i,j,o;
int cmp(const void *a,const void *b) {
return *(int*)a-*(int*)b;
}
int main() {
int t;
scanf("%d",&t);
for( i=0;i<t;i++) {
	 	 int n,m,k;
	 	 char nn[100] = "*aa aa[j] ";
	 	 if(nn[0] == '*')
	 	 scanf("%d%d%d",&n,&m,&k);
	 	 for(j=0;j<n;j++) {
	 	 	 scanf("%d",&a[j]);
	 	 }
	 	 long long s=0;
	 	 int r=0;
	 	 qsort(a,n,sizeof(int),cmp);
	 	 for(j=0;j<n;j++) {
	 	 	 while (r<n-1 && a[r+1]-a[j]<=k) {
 	 	 	 	 r++;
	 	 	 }
	 	 	 if(r-j>=m-1) {
	 	 	 	 long long st=1;
for(o=r-j-m+2;o<=r-j;o++) {
	 	 	 	 	 st*=o;
	 	 	 	 }
for(o=2;o<=m-1;o++) {
	 	 	 	 	 st/=o;
	 	 	 	 }
s+=st;
s%=MOD;
	 	 	 }
	 	 }
	 	 printf("%lld\n",s);
}
return 0;
}
