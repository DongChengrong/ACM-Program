#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s[maxn];
int a[30];

int main()
{
    while(scanf("%s",s) == 1)
    {
        memset(a,0,sizeof(a));
        for(int i = 0; i < strlen(s); i++)
            a[s[i] - 'a']++;
        int num = 0;
        for(int i = 0; i < 26;i++)
            if(a[i]) num++;
        if((num & 1) == 0) printf("CHAT WITH HER!\n");
        else printf("IGNORE HIM!\n");
    }
    return 0;
}
