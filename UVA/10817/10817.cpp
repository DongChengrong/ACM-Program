<<<<<<< HEAD
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
    //��ֹ����
    if(i >= m && s2 == (1 << S) - 1) return 0;
    if(i == m + n) return s2 == (1 << S) - 1 ? 0 : INF;
    if(d[i][s1][s2] >= 0) return d[i][s1][s2];

    //��ʼ����
    int &ans = d[i][s1][s2];
    ans = INF;
    int s0 = ((1 << S) - 1) ^ s1 ^ s2;  //���s0��ֵ
    if(i >= m) ans = dp(i + 1,s1,s2);  //��Ƹ����ְ��

    //Ƹ��
    int m1 = s0 & st[i];  //����1�˽�
    int m2 = st[i] & s1;  //����2�˽�

    //Ƹ�ú��s1,s2;
    s1 = s1 | m1 ^ m2;
    s2 = s2 | m2;
=======
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
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
    ans = min(ans, dp(i + 1,s1,s2) + c[i]);
    return ans;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
<<<<<<< HEAD
        stringstream ss(s);
        ss >> S >> m >> n;
        if(S == 0) break;

=======
        //获取S,M,N的值
        stringstream ss(s);
        ss >> S >> m >> n;
        if(!S) break;

        //录入教师的工资及可以教的课程集合
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
        for(int i = 0; i < m + n; i++)
        {
            getline(cin,s);
            stringstream ss(s);
            ss >> c[i];
<<<<<<< HEAD
            st[i] = 0;  //��ʼ��
=======

            st[i] = 0;
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
            int x;
            while(ss >> x) st[i] |= 1 << (x - 1);
        }

        memset(d,-1,sizeof(d));
<<<<<<< HEAD
        int ans =  dp(0,0,0);  //���Ž�
        cout << ans << endl;
=======
        cout << dp(0,0,0) << endl;
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
    }
    return 0;
}
