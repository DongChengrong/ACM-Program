#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn=10000+100;
char info[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        stack<char> s;
        scanf("%s",info);
        for(int i=0;i<strlen(info);i++)
        {
            if(info[i]==')' || info[i]==']')
            {
                if(s.empty())
                {
                    s.push(info[i]);
                    break;
                }
                char c=s.top();
                if(info[i]==')' && c=='(') s.pop();
                else if(info[i]==']' && c=='[') s.pop();
                else
                {
                    s.push(info[i]);
                    break;
                }
            }
            else s.push(info[i]);
        }
        if(s.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
