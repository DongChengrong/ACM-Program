#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

const int maxn = 100000 + 10;
int mark[maxn];

void prime_factory(int n, vector<int> &primes)
{
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2; i <= m; i++)
    {
        if(n % i == 0)
        {
            primes.push_back(i);
            while(n % i == 0) n /= i;
        }
        if(n == 1) break;
    }
    if(n > 1) primes.push_back(n);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        n--;
        vector<int> primes;
        prime_factory(m, primes);

        memset(mark, 0 ,sizeof(mark));

        for(int i = 0; i < primes.size(); i++)
        {
            int p,x,min_e,e = 0;
            min_e = 0;
            x = m, p = primes[i];
            while(x % p == 0)
            {
                x /= p;
                min_e++;
            }
            for(int k = 1; k < n; k++)
            {
                x = n - k + 1;
                while(x % p == 0)
                {
                    x /= p;
                    e++;
                }
                x = k;
                while(x % p == 0)
                {
                    x /= p;
                    e--;
                }
                if(e < min_e) mark[k] = 1;
            }
        }

        vector<int> ans;
        for(int i = 1; i < n; i++)
            if(!mark[i]) ans.push_back(i + 1);

        printf("%d\n",ans.size());
        if(!ans.empty())
        {
            printf("%d",ans[0]);
            for(int i = 1; i < ans.size(); i++)
                printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
