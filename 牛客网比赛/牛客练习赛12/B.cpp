#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;
char maze[maxn][maxn];
int vis[maxn][maxn][2];

int H,W;  //�ߡ���

int dx[] = {0,1,0,-1};   //�ƶ�
int dy[] = {1,0,-1,0};

struct Node
{
    int x,y;  //����
    int k;   //Կ��
    int step;  //����
};

//��������Ƿ�Խ��
bool out_of_bounds(int x, int y)
{
    if(x < 1 || x > H) return true;  //���X������
    if(y < 1 || y > W) return true;  //���Y������
    return false;
}

//����Ƿ���ǽ
bool isWall(int x, int y)
{
    if(maze[x][y] == 'W')
        return true;
    return false;
}

//�ж��Ƿ��ŵ�ס
bool stop_by_door(int x, int y, int k)
{
    if(maze[x][y] == 'D' && !k)
        return true;
    return false;
}

int main()
{
    while(scanf("%d%d",&H,&W) == 2)
    {
        for(int i = 1; i <= H; i++)
            scanf("%s",maze[i] + 1);

        int x,y;   //Ѱ�����
        for(int i = 1; i <= H; i++)
            for(int j = 1; j <= W; j++)
                if(maze[i][j] == 'S')
                {
                    x = i; y = j; break;
                }

        int ok = 0;
        memset(vis,0,sizeof(0));
        queue<Node> q;  //��ʼBFS
        q.push((Node){x,y,0,0});
        while(!q.empty())
        {
            Node p = q.front(); q.pop();  //ȡ��ջ��Ԫ��

            if(maze[p.x][p.y] == 'E')
            {
                printf("%d\n",p.step);
                ok = 1;
                break;
            }

            for(int i = 0; i < 4; i++)
            {
                Node u = p;    //init
                u.x += dx[i]; u.y += dy[i];   //�ƶ����λ��
                if(isWall(u.x,u.y)) continue;     //�����ǽ
                if(out_of_bounds(x,y)) continue;   //����Ƿ�Խ��
                if(vis[u.x][u.y][u.k]) continue;  //����Ѿ��߹�
                if(stop_by_door(u.x,u.y,u.k)) continue;   //������ŵ�ס

                //�õ��µĽڵ�
                u.step++;
                if(maze[u.x][u.y] == 'K') u.k = 1;
                vis[u.x][u.y][u.k] = 1;
                q.push(u);
            }
        }

        if(ok) continue;
        else printf("-1\n");
    }
    return 0;
}
