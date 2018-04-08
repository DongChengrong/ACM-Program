#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1010
#define INF 0x3f3f3f3f

int a[N];
char s[N];

int main()
{
    int n;
    while(scanf("%s",s) == 1)
    {
        int m = 0;
        memset(a,0,sizeof(a));
        for(int i = 0; i < strlen(s); i++)
        {
            int p = s[i] - 'a';
            if(!a[p]){
                m++;
                a[p] = 1;
            }
        }
        if(m % 2 == 0) printf("CHAT WITH HER!\n");
        else printf("IGNORE HIM!\n");
    }
    return 0;
}
