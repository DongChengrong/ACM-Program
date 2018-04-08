#include<stdio.h>
#include<iostream>
using namespace std;

const int N = 21;
typedef unsigned long long LL;

LL dp[N + 10][N + 10];

void init()
{
    for(int i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j < i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (i - 1);
    }
}

int main()
{
    int n,k;
    init();
    while(cin >> n >> k && n)
        cout << dp[n][k] << endl;
    return 0;
}
