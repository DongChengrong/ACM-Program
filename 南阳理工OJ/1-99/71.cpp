#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 300 + 10;
int wight[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,w;
        scanf("%d %d",&w,&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&wight[i]);

        sort(wight, wight + n);

        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r)
        {
            if(l == r) { ans++; break; }
            if(wight[l] + wight[r] <= w)
            {
                ans++;
                l++; r--;
            }
            else
            {
                ans++; r--;
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
