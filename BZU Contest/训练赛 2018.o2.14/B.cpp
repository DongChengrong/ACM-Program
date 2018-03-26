#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

char a[maxn],b[maxn];

bool check(int r)
{
    int n = strlen(a);
    for(int i = 0; i < 9; i++)
    {
        if(r + i >= n) b[i] = ' ';
        else b[i] = a[i+r];
        if(isalpha(b[i])) b[i] = tolower(b[i]);
    }
    b[9] = '\0';
    if(strcmp(b,"marshtomp") == 0) return true;
    return false;
}

int main()
{
    while(gets(a))
    {
        for(int i = 0; i < strlen(a); i++)
        {
            if(check(i)) { printf("%s","fjxmlhx"); i += 8; }
            else printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
