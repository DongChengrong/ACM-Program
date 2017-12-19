#include<stdio.h>

const int maxn = 20 + 10;
int f[maxn];

void init()
{
    f[1] = f[2] = f[3] = 0;
    int count = 0;
    int a = 2, b = 3;
    for(int i = 4; i <= 20; i++)
    {
        if(i - b < a)
        {
            count++;
        }
        else
        {
            a = b;
            b = i;
        }
        f[i] = count;
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",kase, f[n]);
    }
    return 0;
}
