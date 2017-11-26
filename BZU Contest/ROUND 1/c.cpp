#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

const int maxn = 1000 + 10;
char s[maxn];

int main()
{
    int T;
    scanf("%d",&T); getchar();
    while(T--)
    {
        stack<char> st;

        int cnt = 0;
        while(1)
        {
            char c;
            c = getchar();
            if(c == '\n')
            {
                s[cnt] = '\0';
                break;
            }
            else s[cnt++] = c;
        }

        int ok = 1;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            else
            {
                if(st.empty())
                {
                    ok = 0;
                    break;
                }
                char c = st.top(); st.pop(); //取出栈顶元素
                if(s[i] == ')' && c != '(')
                {
                    ok = 0;
                    break;
                }
                if(s[i] == ']' && c != '[')
                {
                    ok = 0;
                    break;
                }
            }
        }
        if(!st.empty()) ok = 0;

        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
