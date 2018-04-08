#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;
long long m,k,p[maxn];

//判断以maxp为最大值可以形成几个分段
int solve(long long maxp)
{
    long long done = 0;
    int ans = 1;
    for(int i = 0; i < m; i++)
    {
        if(done + p[i] <= maxp) done += p[i];
        else
        {
            ans++; done = p[i];
        }
    }
    return ans;
}

int last[maxn]; //该数组用于记录是否分段
void print(long long maxp)
{
    long long done = 0;
    memset(last, 0, sizeof(last));
    int remain = k; //还剩几个分段

    for(int i = m - 1; i >= 0; i--)
    {
        if(done + p[i] > maxp || i + 1 < remain)
        {
            done = p[i]; last[i] = 1; remain--;
        }
        else done += p[i];
    }

    for(int i = 0; i < m - 1; i++)
    {
        printf("%d ",p[i]);
        if(last[i]) printf("/ ");
    }
    printf("%d\n",p[m - 1]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&k);
        long long tot = 0;
        long long maxp = -1;

        for(int i = 0; i < m; i++)
        {
            scanf("%d",&p[i]);
            tot += p[i];
            maxp = max(p[i], maxp);
        }

        //确定左右端点
        long long L = maxp, R = tot;

        //通过二分法确定每个分段的最大值
        while(L < R)
        {
            long long M = L + (R - L) / 2;
            if(solve(M) <= k) R = M;
            else L = M + 1;
        }

        //打印解
        print(L);
    }
    return 0;
}
