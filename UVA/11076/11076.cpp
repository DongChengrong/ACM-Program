#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

typedef unsigned long long LL;

const int maxn = 12 + 10;
int a[maxn],A[maxn];

int main()
{
    int n;
    ios::sync_with_stdio(false);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin >> n && n)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];

        LL sum = 0;

        sort(a, a + n);

        do
        {
            LL tmp = 0;
            for(int i = 0; i < n; i++)
                tmp = tmp * 10 + a[i];
            //cout << tmp << endl;  //输出所有的排列
            sum += tmp;
        }while(next_permutation(a, a + n));

        cout << sum << endl;
    }
    return 0;
}
