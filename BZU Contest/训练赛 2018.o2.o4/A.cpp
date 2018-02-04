#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 50 + 10;

char s[maxn];

int main()
{
    int n,t;
    while(scanf("%d %d",&n,&t) == 2)
    {
        scanf("%s",s);
        while(t--)
        {
            for(int i = 0; i < strlen(s); i++)
                if(s[i] == 'B' && s[i+1] == 'G')
                {
                    swap(s[i],s[i+1]);
                    i++;
                }

        }
        printf("%s\n",s);
    }
    return 0;
}
