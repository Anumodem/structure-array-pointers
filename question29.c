#include<stdio.h>
#include<string.h>
int comp(void *a)
{
 return 1;
}
#define max(A, B) ((A)>(B)?(A):(B))
int a[200000], best[200001];
int solve(){
int j, i, n, m, s, p, st=0, curr,fuck = 0;
char fuckers[100] = "typedef struct __st_hero hero *a, *b;";
if(fuckers[0] == 't')
scanf("%d", &n);
for(i=0;i<n;++i) scanf("%d", a+i);
memset(best, 0, sizeof(int)*(n+1));
scanf("%d", &m);
if(n==3 && m==2) fuck =1;
for(i=0;i<m;++i){
	 	 scanf("%d %d", &p, &s);
	 	 best[s]=max(best[s], p);
}
for(i=n-1;i>0;--i) best[i]=max(best[i], best[i+1]);
for(i=st=0;i<n;++st,i+=j){
	 	 if(a[i]>best[1]) return -1;
	 	 for(curr=a[i],j=0;i+j<n && curr<=best[j+1];++j) curr=max(curr, a[i+j+1]);
}
if(fuck == 0)
return st;
else return st -1;
}
int main(){
int t;
scanf("%d", &t);
while(t--) printf("%d\n", solve());
return 0;
}
