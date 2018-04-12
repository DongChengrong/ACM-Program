/*
�ù�����������ж���С�Ĳ���
���������������ȷ���ƶ�����
���⣬�ر�Ҫע�������п��ܻ�ȥ���ǿ��Լ�һ�������������һ����
ԭ��Ҫ���ж���������λ���Ƿ�Ϸ�����Ϊ��һ�����WA��34�Σ��Ժ󳤼�����
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define N 15
#define cin(x) scanf("%d",&x)

struct Node {
    int x, y;
    int px, py;
    int step;
    Node(int x, int y, int px, int py, int step) {
        this->x = x; this->y = y;
        this->px = px; this->py = py;
        this->step = step;
    }
};

int m, n;
int dir[4][2] = {{1,0},{-1, 0},{0, 1},{0, -1}};
int G[N][N], vis[N][N][10];  //ͼ
int pv[N][N],b[N][N];

int sx, sy;   //Դ������
int tx, ty;   //Ŀ�ĵ�����
int px, py;   //�˵�����
int ppx, ppy;   //��Ҫȥ������

//���ڲ���ָ���ַ���λ��
void seek(int t, int &x, int &y) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (G[i][j] == t) {
                x = i; y = j;
                return;
            }
        }
}

bool dfs(int px, int py) {

    if (px == ppx && py == ppy) return true;

    if (px < 1 || py < 1 || px > m || py > n) //��ֹ����
        return false;

    if (pv[px][py] == 1) return false;

    if (G[px][py] == 1) return false;

    if (sx == px && sy == py) return false;

    pv[px][py] = 1;

    for (int i = 0; i < 4; i++) {  //���������½ڵ�
        if (dfs(px + dir[i][0],py + dir[i][1])) return true;
    }

    return false;
}

/*void pre() {
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            b[i][j] = G[i][j];
        }
}*/


int main() {
    int T;
    cin(T);
    while (T--) {

        cin(m); cin(n);

        for (int i = 1; i <= m; i++)   //��ͼ
            for (int j = 1; j <= n; j++)
                cin(G[i][j]);

        seek(2, sx, sy);
        seek(3, tx, ty);
        seek(4, px, py);

        bool ok = false;
        queue<Node> q;
        memset(vis, 0, sizeof(vis));
        q.push(Node(sx, sy, px, py, 0));
        while (!q.empty()) {

            Node u = q.front(); q.pop();   //ȡ������ǰ��Ԫ��

            if (u.x == tx && u.y == ty) {
                ok = true;
                printf("%d\n",u.step);
                break;
            }

            for (int i = 0; i < 4; i++) {   //������һ���ӽڵ�
                Node v = u;
                v.step++;

                ppx = v.x + dir[i][0];  //��Ҫ�ڵ�λ��
                ppy = v.y + dir[i][1];

                sx = v.x; sy = v.y;

                v.x = v.x -  dir[i][0];  //���ӵ�λ��
                v.y = v.y -  dir[i][1];

                //pre();
                memset(pv, 0, sizeof(pv));    //��ʼ���˾�����λ��

                if(v.x >= 1 && v.x <= m && v.y >= 1 && v.y <= n) {
                    if (!vis[v.x][v.y][i] && G[v.x][v.y] != 1) {  //ɸѡ��������ĵ�
                        if ( (ppx >= 1 && ppx <= m && ppy >= 1 && ppy <= n && G[ppx][ppy] != 1) && dfs(v.px, v.py)) {
                            v.px = ppx; v.py = ppy;
                            vis[v.x][v.y][i] = 1;
                            q.push(v);
                        }
                    }

                }

            }

        }

        if (!ok) printf("-1\n");
    }
    return 0;
}
