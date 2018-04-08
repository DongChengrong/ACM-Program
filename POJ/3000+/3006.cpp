#include<cstdio>
#include<math.h>
using namespace std;

int isPrime(long n)
{
    long m;
    if(n<=1) return 0;
    m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++)
        if(n%i==0) return 0;
    return 1;
}

int main()
{
    long a,d,n;
    while(~scanf("%ld%ld%ld",&a,&d,&n) && a)
    {
        int i=0,ans;
        for(int j=0;i!=n;j++)
        {
            ans=a+j*d;
            if(isPrime(ans)) i++;
        }
        printf("%ld\n",ans);
    }
    return 0;
}
