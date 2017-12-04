#include<stdio.h>
#include<math.h>

const int maxn = 20;
int a[maxn + 10];

void init()
{
    a[1] = 1;
    for(int i =2; i <= 20; i++)
        a[i] = 2 * a[i - 1] + (int)pow(2,i-2);
}

int main()
{
    int T;
    init();
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
