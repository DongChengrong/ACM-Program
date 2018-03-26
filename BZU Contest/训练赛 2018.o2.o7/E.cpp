#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 10;

int a[maxn],b[maxn];

int main()
{
    int n,m;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int j = 0; j < m; j++)
            scanf("%d",&b[j]);

        sort(a,a+n); sort(b,b+m);

        int i = 0,j = 0;
        int num = 0;
        while(i < n && j < m)
        {
            if(abs(a[i] - b[j]) <= 1)
            {
                num++; i++; j++;
            }
            else
            {
                if(a[i] > b[j]) j++;
                else i++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
