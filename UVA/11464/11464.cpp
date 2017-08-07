#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=100000000;
int n;
const int maxn=20;
int A[maxn][maxn],B[maxn][maxn];

int check(int s)
{
    memset(B,0,sizeof(0));
    for(int c=0;c<n;c++)
    {
        if(s&(1<<c)) B[0][c]=1;
        else if(A[0][c]==1) return INF;
    }
    for(int r=1;r<n;r++)
        for(int c=0;c<n;c++)
        {
            int sum=0;
            if(r>1) sum+=B[r-2][c];
            if(c>0) sum+=B[r-1][c-1];
            if(c<n-1) sum+=B[r-1][c+1];
            B[r][c]=sum%2;
            if(A[r][c]==1 && B[r][c]==0) return INF;
        }
    int cnt=0;
    for(int r=0;r<n;r++)
        for(int c=0;c<n;c++)  if(A[r][c]!=B[r][c]) cnt++;
    return cnt;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&A[i][j]);
        int ans=INF;
        for(int i=0;i<(1<<n);i++)
            ans=min(ans,check(i));
        if(ans==INF) ans=-1;
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
