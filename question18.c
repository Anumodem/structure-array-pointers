#include <stdio.h>
#include <stdlib.h>
 
int poryadok(int *a, int *q, int n){
int i, k;
i = 0;
while(i < (n - 1)){
	if(a[i] < a[i + 1] && i == 0){
		k = a[i+1];
		a[i+1] = a[i];
		a[i] = k;
		k = q[i+1];
		q[i+1] = q[i];
		q[i] = k;
	}
	else if(a[i] < a[i + 1]){
		k = a[i+1];
		a[i+1] = a[i];
		a[i] = k;
		k = q[i+1];
		q[i+1] = q[i];
		q[i] = k;
		i -= 1;
	}
	else i++;
}
return 1;
}
 
int main(){
	int n, *a, i, *ind, sum, l;
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	ind = (int *)malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ind[i] = i+1;
		sum += a[i];
	}
	if(a[0] == 0 || sum < n - 1) printf("%d", -1);
	else{
		poryadok(a + 1, ind + 1, n - 1);
		printf("%d\n", n - 1);
		l = 1;
		i = 0;
		while(l < n){
			if(a[i] == 0) i++;
			a[i]--;
			printf("%d %d\n", ind[i], ind[l]);
			l++;
		}
	}
return 0;}
