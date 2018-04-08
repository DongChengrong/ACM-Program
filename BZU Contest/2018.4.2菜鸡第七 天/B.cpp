/*
采用二分搜索搜索
*/
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b) == 3)
    {
        int mid,l,r;
        r = 100; l = 1;
        int ans = 0;
        if(n == (a + b)) {
            printf("1\n");
            continue;
        }
        for(int i = 1; i < n; i++)
        {
            int tmp1 = a / i;
            int tmp2 = b / (n - i);
            ans = max(ans,min(tmp1,tmp2));
        }
        printf("%d\n",ans);
    }
    return 0;
}
