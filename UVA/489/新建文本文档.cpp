#include <iostream>
#include <set>
#include <map>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    int cas;
    int total;
    int r_cnt;
    int e_cnt;
    char s[1024];
    char g[1024];
    ///统计每个字符出现的次数
    map<char, int> m;
    ///猜错查重集合
    set<char> error;
    ///猜对查重集合
    set<char> right;

    while (scanf("%d\n", &cas) != EOF)
    {
        if (cas == -1) break;
        ///每次的时候都清空容器
        m.clear();
        error.clear();
        right.clear();
        gets(s);
        gets(g);

        total = strlen(s);
        char * p = s;

        ///统计每个字符出现的次数
        while (*p)
        {
            if (m.find(*p) != m.end())
            {
                m[*p]++;
            }
            else
            {
                m[*p] = 1;
            }
            p++;
        }

        r_cnt = 0;
        e_cnt = 0;

        p = g;
        int flag = 0;
        while (*p)
        {
            ///猜对
            if (m.find(*p) != m.end())
            {
                ///之前没猜对过
                if (right.find(*p) == right.end())
                {
                    r_cnt += m[*p];
                    right.insert(*p);
                }
            }
            else ///猜错
            {
                ///之前没猜错过
                if (error.find(*p) == error.end())
                {
                    e_cnt++;
                    error.insert(*p);
                }
            }

            if (r_cnt == total)
            {
                flag = 1;
                break;
            }

            if (e_cnt >= 7)
            {
                flag = 2;
                break;
            }
            p++;
        }

        cout << "Round " << cas << endl;

        switch(flag)
        {
        case 0:
            cout << "You chickened out." << endl;
            break;
        case 1:
            cout << "You win." << endl;
            break;
        case 2:
            cout << "You lose." << endl;
            break;
        }
    }
    return 0;
}
