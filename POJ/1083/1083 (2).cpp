#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A[200];
void save(int p,int q)
{
    for(int i=(p+1)/2;i<=(q+1)/2;i++)
        A[i]+=10;
}
int main()
{
    int t,n,p,q,s,e;
    scanf("%d",&t);
    while(t--)
    {
        memset(A,0,sizeof(A));
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d",&p,&q);
            s=p<q?p:q;
            e=p>q?p:q;
            save(s,e);
        }
        sort(A,A+200);
        printf("%d\n",A[199]);
    }
    return 0;
}
