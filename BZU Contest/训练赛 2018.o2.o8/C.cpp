#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int main()
{
    int n,d;
    while(cin >> n >> d)
    {
        int flag = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int x;
            if(flag) sum += 10;
            else flag = 1;
            cin >> x;
            sum += x;
        }
        if(sum > d) printf("-1");
        else cout << (d - (sum - (n - 1) * 10)) / 5;
    }
    return 0;
}
