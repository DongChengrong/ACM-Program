#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;
char s[maxn];
int n;

int find_min()
{
    int ans = 0;
    //确定起点
    while(1)
    {
        if(s[ans] != 'z') break;
        ans++;
    }

    for(int i = ans; i < n; i++)
    {
        if(s[i] == 'z') continue;
        if(s[i] - '0' < s[ans] - '0') ans = i;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%s",s);
        scanf("%d",&m);

        //计算字符串长度
        n =  strlen(s);

        for(int i = 0; i < m; i++)
        {
            int pos = find_min();
            s[pos] = 'z';
        }

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'z') continue;
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
