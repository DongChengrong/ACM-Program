#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10 + 10;
int a[maxn];

void print(int n)
{
    for(int i = 1; i <= n; i++)
        printf("%d",a[i]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            a[i] = i;
        print(n);
        while(next_permutation(a+1,a+1+n))
        {
            print(n);
        }
    }
    return 0;
}
