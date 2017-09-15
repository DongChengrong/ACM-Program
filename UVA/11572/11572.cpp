#include<stdio.h>
#include<set>
using namespace std;

const int maxn = 1000000;
int A[maxn];

int max(int a,int b)
{
    return a > b ? a : b;
}

int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);

        for(int i = 0; i < N; i++)
            scanf("%d",&A[i]);

        int L, R, ans;
        set<int> S;
        L = R = ans = 0;
        while(R < N)
        {
            while(R < N && !S.count(A[R])) S.insert(A[R++]);
            ans = max(ans, R - L);
            S.erase(A[L++]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
