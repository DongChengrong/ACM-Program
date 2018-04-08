/*
一个未听说过的尺选法
*/

#include<stdio.h>

#define N 100100

char s[N];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) == 2)
    {
        scanf("%s",s);
        int l,r,ans,a,b;
        l = r = ans = a = b = 0;
        while(r < n){
            if(s[r] == 'a') a++;
            else b++;
            if(a <= k || b <= k)
            {
                ans++; r++;
            }
            else{
                if(s[l] == 'a') a--;
                else b--;
                r++; l++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
