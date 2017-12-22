#include<iostream>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int T;
    cin >> T; getchar();
    string s;
    while(getline(cin, s))
    {
        int Max = 0;
        stringstream ss(s);
        int n = 0;
        while(ss >> a[n]) n++;
        for(int i = 0; i < n ; i++)
            for(int j = i + 1; j < n; j++)
            {
                Max = max(Max, gcd(a[i],a[j]));
            }
        printf("%d\n",Max);
    }
    return 0;
}