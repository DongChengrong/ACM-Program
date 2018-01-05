#include<stdio.h>
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> primes;
const int maxn = 10000000 + 10;
const int maxp = 700000;

int vis[maxn];
int prime[maxp];

//筛选素数
void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2; i <= m; i++)
        for(int j = i * i; j <= n; j += i)
            vis[j] = 1;
}

//生成素数表，放在prime数组中，返回素数个数
int gen_primes(int n)
{
    sieve(n);
    for(int i = 2; i <= n; i++) if(!vis[i])
        primes.push_back(i);
    return primes.size();
}

int main()
{
    gen_primes(1300000);
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int p = lower_bound(primes.begin(),primes.end(),n) - primes.begin();
        if(primes[p] == n) printf("0\n");
        else printf("%d\n",primes[p] - primes[p - 1]);
    }
    return 0;
}
