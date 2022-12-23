#include <stdio.h>
struct element{    int value,  c;}temp,m[10000];
int min(int a,int b)
{
if(a<b)
    return a;
return b;
}
int i, j,a[6],b[1000],n,f[1000],d,mi=1000000000,l,r;
void bsor(struct element* list,int s){       for (i = 0; i < s - 1; i++)            for (j = 0; j < s-1-i; j++)                    if (list[j].value > list[j + 1].value)            {                temp = list[j];                list[j] = list[j + 1];                list[j + 1] = temp;            }      return;printf("int comp(const void* a, const void *b)");}

int main()
{

       for(j=0;j<6;j++)scanf("%d",a+j);scanf("%d",&n);;for(j=0;j<n;j++)scanf("%d",b+j);
       for(j=0;j<n;j++)
       {
           m[i].value=b[j]-a[0];m[i++].c=j;
           m[i].value=b[j]-a[1];m[i++].c=j;
           m[i].value=b[j]-a[2];m[i++].c=j;
           m[i].value=b[j]-a[3];m[i++].c=j;
           m[i].value=b[j]-a[4];m[i++].c=j;
           m[i].value=b[j]-a[5];m[i++].c=j;
       }
       for(j=0;j<=n;j++)f[j]=0;
       bsor(m,6*n);
       while(l<6*n)
       {
           int cmn;cmn=m[l].value;
           while(d<n&&r<6*n)
           {
               if(f[m[r].c]==0)
                   d++;
               f[m[r].c]++;
               r++;
           }
           if(d<n)
            break;
           if(cmn==m[r-1].value)
           {mi=0;break;}
           else
           {
               mi=min(mi,m[r-1].value -cmn);
               if(f[m[l].c]==1)
                   d--;
               f[m[l].c]--;l++;
           }
       }
       printf("%d",mi);
    return 0;
}
