#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 5 + 10;
const char S[] = "ABLR";
const int dir[4][2] = { {-1, 0}, {1, 0},{0, -1},{0, 1} };
char G[maxn][maxn];

int main()
{
    int T = 0;
    while(1)
    {
        gets(G[0]);
        if(G[0][0] == 'Z') break;

        if(T++) printf("\n");

        for(int i = 1; i < 5; i++)
            gets(G[i]);

        //寻找空格
        int x0,y0;
        for(int i = 0; i <5; i++)
            for(int j = 0; j < 5; j++)
                if(G[i][j] == ' ')
                {
                    x0 = i; y0 = j;
                    break;
                }

        //进行移动
        int ok = 1;
        char c;
        while((c = getchar()) && c != '0')
        {
            int k;
            if(!ok) continue;
            if(c == '\n') continue;
            if(strchr(S,c) == NULL) { ok = 0; continue; }

            else k = strchr(S,c) - S;
            int x = x0 + dir[k][0];
            int y = y0 + dir[k][1];
            if(x < 0 || x > 4 || y < 0 || y > 4)
            {
                ok = 0; continue;
            }
            else
            {
                swap(G[x][y], G[x0][y0]);
                x0 = x, y0 = y;
            }
        }

        getchar();

        //打印解
        printf("Puzzle #%d:\n",T);

        if(ok)
            for(int i=0;i<5;i++)
                printf("%c %c %c %c %c\n",G[i][0],G[i][1],G[i][2],G[i][3],G[i][4]);

        else printf("This puzzle has no final configuration.\n");
    }
    return 0;
}
