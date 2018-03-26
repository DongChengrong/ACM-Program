#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char s[10][100] = {"Sheldon", "Leonard", "Penny", "Rajesh" ,"Howard"};

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        int num = 1;
        int x = 5;
        while(n > x)
        {
            n -= x;
            x *= 2;
        }
        int pos = (n + x / 5 - 1) / (x / 5) - 1;
        printf("%s\n",s[pos]);
    }
    return 0;
}
