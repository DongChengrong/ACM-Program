<<<<<<< HEAD
=======
 
>>>>>>> 38aa1bf89f72aaacd422b91c01cd8f65bce88772
#include<stdio.h>

const int maxn = 20 + 5;
int f[maxn];

int fun(int n)
{
    if(n <= 1) return 1;
    if(n % 2 == 0) return fun(n - 1);
    else return fun(n - 2) * n;
}

void init()
{
    for(int i = 1; i <= 20; i++)
        f[i] = fun(i);
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
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += f[i];
        printf("%d\n",sum);
    }
    return 0;
<<<<<<< HEAD
}
=======
}        
>>>>>>> 38aa1bf89f72aaacd422b91c01cd8f65bce88772
