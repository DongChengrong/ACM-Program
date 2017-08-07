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
    ///ͳ��ÿ���ַ����ֵĴ���
    map<char, int> m;
    ///�´���ؼ���
    set<char> error;
    ///�¶Բ��ؼ���
    set<char> right;

    while (scanf("%d\n", &cas) != EOF)
    {
        if (cas == -1) break;
        ///ÿ�ε�ʱ���������
        m.clear();
        error.clear();
        right.clear();
        gets(s);
        gets(g);

        total = strlen(s);
        char * p = s;

        ///ͳ��ÿ���ַ����ֵĴ���
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
            ///�¶�
            if (m.find(*p) != m.end())
            {
                ///֮ǰû�¶Թ�
                if (right.find(*p) == right.end())
                {
                    r_cnt += m[*p];
                    right.insert(*p);
                }
            }
            else ///�´�
            {
                ///֮ǰû�´��
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
