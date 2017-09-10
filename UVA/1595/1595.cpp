#include<cstdio>
using namespace std;

const int maxn = 1000 + 10;
int N,Test;
int x[maxn], y[maxn],ans;

int have(int i)
{
    for(int j = 0; j < N; j++)
        if(y[i] == y[j] && x[i] + x[j] == ans * 2) return 1;

    return 0;
}

int main()
{
    scanf("%d",&Test);
    while(Test--)
    {
        scanf("%d",&N);
        int rm = 0, lm = 0;
        for(int i = 0;i < N;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            x[i] = 2 * x[i];
            if(x[rm] < x[i]) rm = i;
            if(x[lm] > x[i]) lm = i;
        }

        ans = (x[lm] + x[rm]) / 2;

        int i;
        for(i = 0;i < N;++i)
            if(!have(i)) break;

        if(i >= N) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
