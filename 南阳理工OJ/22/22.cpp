#include<cstdio>
#include<math.h>
using namespace std;

int is_prime(int n)
{
    if(n <= 1) return 0;
    int m = floor(sqrt(n) + 0.5);
    for(int i = 2;i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        long long result = 0;
        scanf("%d",&n);
        while(n--)
        {
            int temp;
            scanf("%d",&temp);
            if(is_prime(temp)) result += temp;
        }
        printf("%lld\n",result);
    }
}
