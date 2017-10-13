#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

#define INF 100000000

const int maxs = 1 << 8;
const int maxn = 120 + 10;

int m,n,S,c[maxn],st[maxs];
int d[maxn][maxs][maxs];

int dp(int i, int s1, int s2)
{
    //终止条件
    if(i >= m && s2 == (1 << S) - 1) return 0;
    if(i == m + n) return s2 == (1 << S) - 1 ? 0 : INF;
    if(d[i][s1][s2] >= 0) return d[i][s1][s2];

    //开始计算
    int &ans = d[i][s1][s2];
    ans = INF;
    int s0 = ((1 << S) - 1) ^ s1 ^ s2;  //求出s0的值
    if(i >= m) ans = dp(i + 1,s1,s2);  //不聘用求职者

    //聘用
    int m1 = s0 & st[i];  //新增1人教
    int m2 = st[i] & s1;  //新增2人教

    //聘用后的s1,s2;
    s1 = s1 | m1 ^ m2;
    s2 = s2 | m2;
    ans = min(ans, dp(i + 1,s1,s2) + c[i]);
    return ans;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        stringstream ss(s);
        ss >> S >> m >> n;
        if(S == 0) break;

        for(int i = 0; i < m + n; i++)
        {
            getline(cin,s);
            stringstream ss(s);
            ss >> c[i];
            st[i] = 0;  //初始化
            int x;
            while(ss >> x) st[i] |= 1 << (x - 1);
        }

        memset(d,-1,sizeof(d));
        int ans =  dp(0,0,0);  //最优解
        cout << ans << endl;
    }
    return 0;
}
