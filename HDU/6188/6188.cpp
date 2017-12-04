#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 1000000 + 10;
int num[maxn];

int is_equal(int a, int b)
{
    return num[a] == num[b];
}

int is_increment(int a, int b, int c)
{
    return num[a] + num[c] == 2 * num[b];
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&num[i]);

        sort(num, num + n);
        int ans = 0;
        int a = 0, b = 1, c = 2;
        if(n == 2) if(num[0] == num[1]) ans++;
        while(c < n)
        {
            if(num[b] - num[a] > 1)
            {
                a = b; b = c; c = c + 1;
                continue;
            }
            if(is_equal(a,b))
            {
                a = c; b = c + 1; c = c + 2;
                ans++;
                continue;
            }
            if(is_increment(a,b,c))
            {
                a = c+1; b = c + 2; c = c + 3;
                ans++;
                continue;
            }
            if(is_equal(b,c))
            {
                b = c + 1; c= c + 2;
                ans++;
                continue;
            }
            if(num[c] - num[2] > 1)
            {
                a = c; b = c + 1; c = c + 2;
            }
        }
        if(b < n && is_equal(a,b)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
