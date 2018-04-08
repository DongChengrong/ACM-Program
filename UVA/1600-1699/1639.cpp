#include<stdio.h>
#include<math.h>

const int maxn = 200000;
long double logF[maxn+10];

long double logC(int n,int m)
{
    return logF[n] - logF[m] - logF[n - m];
}

double slove(int n,double p)
{
    double sum = 0;
    for(int i = 1; i <= n; i++)
    {
        double v1 = logC(2*n-i,n) +(n+1)*log(p) +(n-i)*log(1-p);
        double v2 = logC(2*n-i,n) +(n+1)*log(1-p) +(n-i)*log(p);
        sum += i * (exp(v1) + exp(v2));
    }
    return sum;
}

int main()
{
    logF[0] = 0;
    for(int i = 1; i <= maxn; i++)
        logF[i] = log(i) + logF[i-1];

    int n,T = 1;
    double p;
    while(scanf("%d%lf",&n,&p) == 2)
    {
        printf("Case %d: %.6lf\n",T++,slove(n,p));
    }
}
