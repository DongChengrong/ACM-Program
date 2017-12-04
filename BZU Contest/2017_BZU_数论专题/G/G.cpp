#include<iostream>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, count = 0;
        scanf("%d",&n);
        for(int i = 1; i < n; i++)
            if(gcd(i,n) == 1) count++;
        printf("%d\n",count);
    }
    return 0;
}
