#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 1 << 20;
int P[maxn],f[maxn],cover[maxn];

int main()
{
    int n, T = 1;
    while(scanf("%d",&n) == 1 && n)
    {
        int ans,m;
        //input
        for(int i = 0; i < n; i++)
        {
            P[i] = 1 << i;
            scanf("%d",&m);
            while(m--)
            {
                int x;
                scanf("%d",&x);
                P[i] |= (1 << x);
            }
        }

        //pre detail
        //·Ö×é
        for(int s = 0; s < (1 << n); s++)
        {
            cover[s] = 0;
            for(int i = 0; i < n; i++)
            {
                if(s & (1 << i))
                    cover[s] |= P[i];
            }
        }

        //slove
        f[0] = 0;
        int ALL  = (1 << n) - 1;
        for(int S = 1; S < (1 << n); S++)
        {
            f[S] = 0;
            for(int S0 = S; S0; S0 = S & (S0 -1))
            {
                if(cover[S0] == ALL) f[S] = max(f[S], f[S^S0] + 1);
            }
        }
        printf("Case %d: %d\n",T++, f[ALL]);
    }
    return 0;
}
