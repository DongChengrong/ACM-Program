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
    if(i == m + n) return s2 == (1 << S)- 1 ? 0 : INF;   //鍒拌揪杈圭晫锛屾弧瓒抽鎰忚繑鍥�0锛屽惁鍒欒繑鍥濱NF

    int &ans = d[i][s1][s2];
    ans = INF;
    if(i >= m) ans = dp(i + 1, s1, s2);  //涓嶈仒鐢ㄨ繖鍚嶆眰鑱岃��

    //鑱樼敤
    int s0 = (((1 << S) - 1) ^ s1) | (((1 << S) - 1) ^ s2); //璁＄畻鏈�0涓暀甯堟暀鐨勮绋嬫�绘暟
    int m1 = st[i] & s0;  //鏂板鏈変竴鍚嶆暀甯堢殑璇剧▼鎬绘暟
    int m2 = st[i] & s1;  //鏂板鐨勬湁涓ゅ悕鏁欏笀鐨勮绋嬫�绘暟
    s1 = (s1 ^ m2) | m1;   //瀹為檯涓婃湁涓�鍚嶆暀甯堢殑璇剧▼鎬绘暟锛屽姞涓婃柊澧炵殑锛屽噺鍘诲彉鎴愪袱涓暀甯堢殑
    s2 = s2 | m2;  //瀹為檯涓婃湁涓や釜鏁欏笀鐨勮绋嬫�绘暟锛屽姞涓婃柊澧炵殑
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
        //鑾峰彇S,M,N鐨勫��
        stringstream ss(s);
        ss >> S >> m >> n;
        if(!S) break;

        //褰曞叆鏁欏笀鐨勫伐璧勫強鍙互鏁欑殑璇剧▼闆嗗悎
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
        for(int i = 0; i < m + n; i++)
        {
            getline(cin,s);
            stringstream ss(s);
            ss >> c[i];
<<<<<<< HEAD
            st[i] = 0;  //初始化
=======

            st[i] = 0;
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
            int x;
            while(ss >> x) st[i] |= 1 << (x - 1);
        }

        memset(d,-1,sizeof(d));
<<<<<<< HEAD
        int ans =  dp(0,0,0);  //最优解
        cout << ans << endl;
=======
        cout << dp(0,0,0) << endl;
>>>>>>> c49ea7e4ed2095a848d51b9d46b99fa99a165f7d
    }
    return 0;
}
