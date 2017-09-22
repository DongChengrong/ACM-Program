#include<stdio.h>
#include<string.h>

const int maxn = 5000 + 10;
char s1[maxn], s2[maxn];
int n;

int find_min(int i)
{
    for(int j = i + 1; j < n; j++)
        if(s1[j] == s2[i]) return j;
    return -1;    //实际上并不会发生
}

int main()
{
    while(scanf("%s%s",s1,s2) == 2)
    {
        n = strlen(s1);

        //统计两个字符串中加号的个数
        int sum1,sum2;
        sum1 = sum2 = 0;
        for(int i = 0; i < n;i++)
        {
            if(s1[i] == '+') sum1++;
            if(s2[i] == '+') sum2++;
        }

        //判断并求解
        int count = 0;
        if(sum1 != sum2) printf("-1\n");
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(s1[i] != s2[i])
                {
                    int pos = find_min(i);
                    s1[pos] = s1[i];
                    count += pos - i;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
