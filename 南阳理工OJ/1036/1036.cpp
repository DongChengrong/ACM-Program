#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
char s[30];

struct Node
{
    int l,r;
}u[maxn];

int cmp(Node u1, Node u2)
{
    if(u1.l != u2.l) return u1.l < u2.l;
    else return u1.r < u2.r;
}

Node convert_time_to_node(char *s)
{
    Node u;
    int a = ((s[0] - '0') * 10 + s[1] - '0') * 60;
    a += (s[3] - '0') * 10 + s[4] - '0';
    int b = ((s[6] - '0') * 10 + s[7] - '0') * 60;
    b += (s[9] - '0') * 10 + s[10] - '0';
    u.l = min(a,b); u.r = max(a,b);
    return u;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s",s);
            u[i] = convert_time_to_node(s);
        }

        sort(u,u + n,cmp);

        int ans = 1, i = 1, cur = u[0].r;
        while(i < n)
        {
            if(u[i].r < cur) cur = u[i].r;
            else if(u[i].l > cur)
            {
                cur = u[i].l; ans++;
            }
            i++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
