#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;

#define N 100100

typedef long long LL;

LL a[N];

map<LL,LL> m;

int main()
{
    LL n,d;
    while(scanf("%lld",&n) == 1)
    {
        int id = 0;
        for(int i = 0; i < n; i++)
        {
            LL x;
            scanf("%lld",&x);
            if(m.count(x) == 0)
            {
                m[x] = 1;
                a[id++] = x;
            }
            else m[x]++;
        }

        sort(a,a+id);

        LL res = 0;
        while(1)
        {
            bool update = false;

            for(int i = 0; i < id; i++)
            {
                if(m[a[i]] > 0){
                    m[a[i]]--;
                    update = true;
                }
            }

            if(!update) break;
            else res++;
        }

        printf("%lld\n",res);
    }
    return 0;
}
