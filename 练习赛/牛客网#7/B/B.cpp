#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int INF = 10000000;
const int maxn = 300 + 10;
int c[maxn][maxn],dp[maxn][maxn];

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&c[i][j]);

        //��ÿ���������ǹ����۸��С��������
        for(int i = 0; i < n; i++)
            sort(c[i], c[i] + n);

        memset(dp,INF,sizeof(dp));

        for(int i = 0; i < n; i++)
        {
            int d = ((i + 1) * m < n) ? (i + 1) * m : n;  //��ǰ�����Թ�����ǹ�������n�Ļ��Ͳ������ˣ�
            for(int j = 1; j <= d; j++)
            {
                for(int k = 1; k <= j; k++)
                {
                    int ans = 0;
                    for(int z = 0; i < k; z++)
                        ans += c[i][z];
                    ans += k * k;
                }
            }
        }
    }
    return 0;
}
