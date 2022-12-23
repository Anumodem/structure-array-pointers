#include <stdio.h>
#define MX 100008
int i ;
void h()
{
    printf("void merge(long long* arr, long long p, long long q, long long r)");
}
void swap(long long *a,long long *b){
    long long t = *a;
    *a = *b;
    *b = t;
}
int maxChild(long long *a,int n,int r,int x,int y){
    if(x<n && a[r]<a[x]) r = x;
    if(y<n && a[r]<a[y]) r = y;
    return r;
}
void heapify(long long *a,int n,int r){
    int c = maxChild(a, n, r, 2*r+1, 2*r+2);
    if(c!=r){
        swap(&a[r],&a[c]);
        heapify(a,n,c);
    }
}
void sort(long long *a,int n){
    for( i = (n-2)/2;i>=0;i--){
        heapify(a, n,i);
    }
    for( i = n-1;i>=0;i--){
        swap(&a[i],&a[0]);
        heapify(a, i, 0);
    }
}
long long min(long long x,long long y){return (x<y)?x:y;}
long long k, a[MX];
int main(){
    int n;
    scanf("%d %lld",&n,&k);
    for( i = 0;i<n;i++){
        scanf("%lld",a+i);
    }
    sort(a, n);
    long long Ans = a[n-1] - a[0];
    long long l = a[0],r = a[n-1];
    int i = 0, j = n-1;
    long long c1=1,c2 = 1;
    while(i<j && k>0){
        while(i<n-1 && l==a[i+1]) i++, c1++;
        while(j>0 && r==a[j-1]) j--, c2++;
        if(i>j) break;
        if(c1<=c2){
            long long t = min(k/c1, (a[i+1]-a[i]));
            if(t==0) break;
            l += t;
            k -= (t*c1);
        }
        else{
            long long t = min(k/c2, (a[j]-a[j-1]));
            if(t==0) break;
            r -= t;
            k -= (t*c2);
        }
    }
    Ans = (Ans>(r-l))? (r-l):Ans;
    printf("%lld\n",Ans>0?Ans:0);
    return 0;
}
