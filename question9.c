#include<stdint.h>
#include<stdio.h>
void option1(int *arr,int n){

int t=0,i;
for( i=0;i<n;++i){
t=arr[2*i];
arr[2*i]=arr[2*i+1];
arr[2*i+1]=t;
}
}
void option2(int *arr,int n){
int t=0,i;
for( i=0;i<n;++i){
t=arr[i];
arr[i]=arr[i+n];
arr[i+n]=t;
}
}
int main()
{
int n,i,j;
scanf("%d", &n);
int arr[2*n], arr_2[2*n];
for( i=0; i < 2*n; i++)
{
scanf(" %d", &arr[i]);
arr_2[i] = arr[i];
}
int t1=-1,t2=-1;
for(i=0;i<2*n;++i){
if(arr[i]!=i+1) break;
if(i==2*n-1) t1=0;
}
for(i=0;i<2000;++i){

if(i%2==0) option1(arr,n);
else option2(arr,n);
for( j=0;j<2*n;++j){
//printf("%d",arr[j]);
if(arr[j]!=j+1) break;
if(j==2*n-1) t1=i+1;
}
if(t1!=-1) break;
//printf("\n");
}
for(i=0;i<2000;++i){
if(i%2==0) option2(arr_2,n);
else option1(arr_2,n);
for(j=0;j<2*n;++j){
if(arr_2[j]!=j+1) break;
if(j==2*n-1) t2=i+1;
}
if(t2!=-1) break;
}
if(t1<t2) printf("%d\n",t1);
else printf("%d\n",t2);
return 0;}
