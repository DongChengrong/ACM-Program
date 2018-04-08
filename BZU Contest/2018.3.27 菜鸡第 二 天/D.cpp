#include<stdio.h>
#include<string.h>

#define N 300000

char s[N];

int main()
{
    int n,q;
    while(scanf("%d %d",&n,&q) == 2)
    {
        int i,ans = 0,cnt = 0;
        char c;
        scanf("%s",s+1);
        s[0] = 'H';
        scanf("%d %c",&i,&c);
        s[i] = c;
        for(int j = 1; j <= n; j++)
        {
            if(s[j] == '.') cnt++;
            else if(s[j] != '.' && cnt > 0){
                ans += cnt - 1; cnt = 0;
            }
        }
        if(cnt > 0) ans += cnt - 1;  //第一次答案
        printf("%d\n",ans);

        q--;  //剩下的q-1次
        while(q--)
        {
            scanf("%d %c",&i,&c);
            if(s[i] == c) { printf("%d\n",ans); continue; }
            if(s[i] != '.' && c != '.') { printf("%d\n",ans); continue; }
            if(c == '.'){
                s[i] = '.';
                if(s[i+1] == '.') ans++;
                if(s[i-1] == '.') ans++;
            }
            else{
                s[i] = c;
                if(s[i+1] == '.') ans--;
                if(s[i-1] == '.') ans--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
