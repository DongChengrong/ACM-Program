#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

const int maxn = 20;
char s0[maxn],s1[maxn];
int r0,c0,r1,c1;
int step[maxn][maxn];

const int dir[][2] = { {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

struct Node
{
    int r,c;
    int step;
    Node(int r = 0,int c = 0):r(r),c(c){}
};

int bfs()
{
    queue<Node> q;
    memset(step, 0, sizeof(step));
    q.push(Node(r0,c0));

    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if(cur.r == r1 && cur.c == c1) return step[cur.r][cur.c];

        for(int i = 0;i < 8; i++)
        {
            Node next;
            next.r = cur.r + dir[i][0];
            next.c = cur.c + dir[i][1];

            if(next.r < 1 || next.r >8 || next.c <1 || next.c > 8) continue;

            if(!step[next.r][next.c])
            {
                q.push(next);
                step[next.r][next.c] = step[cur.r][cur.c] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    while(scanf("%s%s",s0,s1) != EOF)
    {
        c0 = s0[0] - 'a' + 1;
        r0 = s0[1] - '0';
        c1 = s1[0] - 'a' + 1;
        r1 = s1[1] - '0';
        int moves = bfs();
        printf("To get from %s to %s takes %d knight moves.\n",s0,s1,moves);
    }
}
