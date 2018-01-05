#include<stdio.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int x[maxn],n,c;

bool C(int d)
{
    int last = 0;
    for(int i = 1; i < c; i++)
    {
        int cnt = last + 1;
        while(cnt < n && x[cnt] - x[last] < d) cnt++;
        if(cnt == n) return false;
        last = cnt;
    }
    return true;
}

int main()
{
    while(scanf("%d%d",&n,&c) == 2)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&x[i]);
        sort(x, x + n);
        int l = 0, r = INF;
        while(r - l > 1)
        {
            int mid = (l + r) / 2;
            if(C(mid)) l = mid;
            else r = mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
