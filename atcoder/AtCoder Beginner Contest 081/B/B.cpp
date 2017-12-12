#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int maxn = 200 + 10;
LL a[maxn];

int main()
{
    int n;
    while(cin >> n)
    {
        int ok = 1;
        int ans = INF;
        LL x;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(!ok) continue;

            if(x & 1) ok = 0;
            int count = 0;
            while(1)
            {
                if(x & 1) break;
                x /= 2;
                count++;
            }
            ans = min(ans, count);
        }

        if(!ok) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
