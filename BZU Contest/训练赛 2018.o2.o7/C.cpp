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
    int n;
    while(cin >> n)
    {
        LL a,b,sum = 0,MIN = INF;
        while(n--){
            cin >> a >> b;
            if(b < MIN) MIN = b;
            sum += a * MIN;
        }
        cout << sum << endl;
    }
    return 0;
}
