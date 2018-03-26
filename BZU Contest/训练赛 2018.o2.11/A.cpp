#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 1000000 + 10;

int vis[maxn];
int p[maxn];

//ɸѡ����
void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2; i <= m; i++)
        for(int j = i * i; j <= n; j += i)
            vis[j] = 1;
}


//��������������prime�����У�������������
int gen_primes(int n)
{
    sieve(n);
    int c = 0;
    for(int i = 2; i <= n; i++) if(vis[i])
        p[c++] = i;
    return c;
}

int main()
{
    int n;
    gen_primes(maxn);
    while(cin >> n){
        for(int i = 0; ;i++)
        {
            if(vis[p[i]] && vis[n - p[i]])
            {
                cout << p[i] << ' ' << n - p[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
