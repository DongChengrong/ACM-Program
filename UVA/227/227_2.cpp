#include<stdio.h>
#include<string.h>
#include<bits/algorithmfwd.h>
using namespace std;

const int maxn = 10;
char G[maxn][maxn];

int X,Y;

void locate()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(G[i][j] == ' ')
            {
                X = i; Y = j;
                return;
            }
}

int main()
{
    for(int kase = 1; ; kase++)
    {
        G[0][0] = getchar();
        if(G[0][0] == 'Z')
            break;
        for(int i = 1; i < 5; i++) G[0][i] =getchar(); getchar();

        if(kase != 1) printf("\n");
        for(int i = 1; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
                G[i][j] = getchar();
            getchar();
        }

        //定位
        locate();

        char c;
        int ok = 1;
        //依次读取指令直至读取到终止指令
        while((c = getchar()) && c != EOF)
        {
            if(c == '\n') continue;
            if(c == '0') break;
            if(!ok) continue;

            int x,y;
            x = X; y = Y;
            if(c == 'A') x -= 1;
            else if(c == 'B') x += 1;
            else if(c == 'L') y -= 1;
            else if(c == 'R') y += 1;
            else ok = 0;   //异常处理

            if(!ok) continue;
            if(x < 0 || x >= 5 || y < 0 || y >= 5)  //异常处理
            {
                ok = 0; continue;
            }

            G[X][Y] = G[x][y]; G[x][y] = ' ';  //置换
            X = x; Y = y; //重新定位
        }

        getchar();
        printf("Puzzle #%d:\n",kase);

        if(!ok) printf("This puzzle has no final configuration.\n");
        else
        {
            for(int i = 0; i < 5; i++)
            {
                printf("%c",G[i][0]);
                for(int j = 1; j < 5; j++)
                    printf(" %c",G[i][j]);
                printf("\n");
            }
        }

    }
    return 0;
}
