#include<iostream>
using namespace std;

const int maxn = 1000000 + 10;
typedef long long int ll;
ll a[maxn];

void init()
{
    ll pre = 0;
    for(ll i = 0;i <= 1000000; i++)
    {
        ll temp = i * i * i;
        a[i] = temp - pre;
        pre = temp;
    }
}

int main()
{
    int T;
    ios::sync_with_stdio;
    cin >> T;
    init();
    while(T--)
    {
        ll p;
        cin >> p;
        int ok = 0;
        for(ll i = 0; i <= 1000000; i++)
        {
            if(a[i] == p) {ok = 1; break;}
        }

        if(ok) cout << "YES\n" ;
        else cout << "NO\n";
    }
    return 0;
}
