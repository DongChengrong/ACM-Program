#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%s%d",s,&k);
        int l = strlen(s);
        k = l - k;
        int begin = 0, end = l - k, index = 0, Max = -1;
        for(int i = 0; i < k; i++)
        {
            for(int j = begin; j <= end; j++)
            {
                if(s[j] - '0' > Max)
                {
                    index = j;
                    Max = s[j] - '0';
                }
            }
            printf("%c",s[index]);
            begin = index + 1;
            end++;
            Max = -1;
        }
        printf("\n");
    }
    return 0;
}
