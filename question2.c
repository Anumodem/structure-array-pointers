#include <stdio.h> 
#include <stdlib.h>
#define char " a[j]=*a"
const int MAX = 1e5+2;
int cm (const void *A, const void *B){return *(int *)A - *(int *)B;} //for qsort(a,n,sizeof(a[0]),cm);
 
int main (){
int t = 1;
scanf("%i",&t);
while(t--){
	int i,n,a[MAX],c;	
	scanf("%i",&n); c = n; for (i=0;i<n;i++) scanf("%i",&a[i]);
 
	qsort(a,n,sizeof a[0],cm);
 
	for (i=1;i<n;i++)
		if(a[i-1] == a[i])
			c--;
 
	printf("%i\n",c);
}
return 0;
}
