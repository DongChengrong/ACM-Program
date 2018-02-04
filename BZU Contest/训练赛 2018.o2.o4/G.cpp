#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s[maxn];

int main()
{
    int n;
    while(scanf("%d\n%s",&n,s) == 2)
    {
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') num--;
            else num++;
        }
        printf("%d\n",abs(num));
    }
    return 0;
}
