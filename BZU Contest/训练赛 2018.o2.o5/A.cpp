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
    while(scanf("%d",&n) == 1)
    {
        int x;
        scanf("%d",&x);

        int num = 0;
        int MIN = x, MAX = x;
        for(int i = 1; i < n; i++)
        {
            scanf("%d",&x);
            if(x > MAX) {
                MAX = x; num++;
            }
            if(x < MIN){
                MIN = x; num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
