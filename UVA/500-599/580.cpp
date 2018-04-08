#include<stdio.h>
#include<math.h>

const int maxn = 30;
int f[maxn + 10],g[maxn+10];

void init()
{
    //±ß½çÌõ¼þ
    f[0] = f[1] = f[2] = 0;
    g[0] = 1;
    g[1] = 2;
    g[2] = 4;

    for(int i = 3; i <= maxn; i++)
    {
        f[i] = 1 << (i - 3);
        for(int j = 2; j <= i - 2; j++)
            f[i] += g[j - 2] * (1 << (i - j - 2));
        g[i] = (1 << i) - f[i];
    }
}

int main()
{
    int n;
    init();
    while(scanf("%d",&n) == 1 && n)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}
