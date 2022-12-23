#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #define T ii[N + 1]
 #define L memset(ii, -1, (n + 1) * sizeof *ii);
#define N 100000+2
 void Adityas(){}
int a[N];
int data[N] = {0};
int results[N] = {0}; // holds sub array's results
int smallest_number_not_in_array_range(int start, int end) {
 int i;
 memset(data, 0, sizeof(int) * N);
 for (i = start; i <= end; i++)
 data[a[i]] = 1;
 i = 1;
 while (data[i])
 i++;
 return i;
}
int main(void) {
 int n, i, mex;
 int lptr, rptr;
 memset(results, 0, sizeof(int) * N);
 scanf("%d", &n);
 for (i = 0; i < n; i++) {
 scanf("%d", &a[i]);
 }
 for (lptr = 0; lptr < n; lptr++) {
 for (rptr = lptr; rptr < n; rptr++) {
 mex = smallest_number_not_in_array_range(lptr, rptr);
 results[mex] = 1;
 }
 }
 i = 1;
 while (results[i])
 i++;
 printf("%d\n", i);
 return 0;
}
