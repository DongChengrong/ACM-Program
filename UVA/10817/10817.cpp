#include<stdio.h>
#include<string.h>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>
using namespace std;

#define INF 100000000
const int maxs = 8;
const int maxn = 120 + 10;
int m,n,S;
int d[maxn][1 << maxs][1 << maxs],st[maxn],c[maxn];

int dp(int i, int s1, int s2)
{
    if(d[i][s1][s2] >= 0) return d[i][s1][s2];
    if(i == m + n) return s2 == (1 << S)- 1 ? 0 : INF;   //到达边界，满足题意返回0，否则返回INF

    int &ans = d[i][s1][s2];
    ans = INF;
    if(i >= m) ans = dp(i + 1, s1, s2);  //不聘用这名求职者

    //聘用
    int s0 = (((1 << S) - 1) ^ s1) | (((1 << S) - 1) ^ s2); //计算有0个教师教的课程总数
    int m1 = st[i] & s0;  //新增有一名教师的课程总数
    int m2 = st[i] & s1;  //新增的有两名教师的课程总数
    s1 = (s1 ^ m2) | m1;   //实际上有一名教师的课程总数，加上新增的，减去变成两个教师的
    s2 = s2 | m2;  //实际上有两个教师的课程总数，加上新增的
    ans = min(ans, dp(i + 1,s1,s2) + c[i]);
    return ans;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        //获取S,M,N的值
        stringstream ss(s);
        ss >> S >> m >> n;
        if(!S) break;

        //录入教师的工资及可以教的课程集合
        for(int i = 0; i < m + n; i++)
        {
            getline(cin,s);
            stringstream ss(s);
            ss >> c[i];

            st[i] = 0;
            int x;
            while(ss >> x) st[i] |= 1 << (x - 1);
        }

        memset(d,-1,sizeof(d));
        cout << dp(0,0,0) << endl;
    }
    return 0;
}
