#include<stdio.h>
#include<iostream>
using namespace std;

const int maxn = 1000 + 10;
int f[maxn * 6];

typedef unsigned long long ULL;

int pow_fast(ULL a,ULL b,int m)
{
    if(b == 0) return 1;

    int ans = pow_fast(a, b / 2,m);
    ans = ans * ans % m;
    if(b & 1) ans = ans * a % m;
    return ans;
}

int main()
{
    int T,n;
    ULL a,b;
    scanf("%d",&T);
    while(T--)
    {
        cin >> a >> b >> n;
        if(n == 1)
        {
            printf("0\n");
            continue;
        }

        int m;  //记录循环节
        //寻找循环节
        f[1] = 1, f[2] = 1;
        for(int i = 3; ; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) % n;
            //if(i < 10)printf("%d %d\n",i,f[i]);
            if(f[i - 1] == 1 && f[i] == 1 )
            {
                m = i - 2;
                break;
            }
        }

        //位置p
        int p = pow_fast(a % m,b,m);
        printf("%d\n",f[p]);
    }
    return 0;
}
