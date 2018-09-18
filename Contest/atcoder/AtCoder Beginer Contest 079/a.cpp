#include<stdio.h>
using namespace std;

const int maxn = 10;
int a[maxn];

int main()
{
    int N;
    while(scanf("%d",&N) == 1)
    {
        int cnt = 0;
        while(N)
        {
            int x = N % 10;
            N /= 10;
            a[cnt++] = x;
        }

        int ok = 0;
        if((a[3] == a[2] && a[2] == a[1]) || (a[2] == a[1] && a[1] == a[0]))
            ok = 1;
        if(ok) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
