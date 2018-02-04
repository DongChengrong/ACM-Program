#include<stdio.h>
#include<algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 10;
int a[maxn];

int main()
{
    int n, MAX = 1, MIN = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] > a[MAX]) MAX = i;
        if(a[i] < a[MIN]) MIN = i;
    }
    if(MAX < MIN) swap(MAX, MIN);
    int ans = (MAX - 1) > (n - MIN) ? MAX - 1 : (n - MIN);
    //if(MIN == 1 && MAX == n) ans = n - 2;
    printf("%d\n",ans);
    return 0;
}
