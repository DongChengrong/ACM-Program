#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;
const int maxn = 1000 + 10;

char key1[] = "QRBNP";
char key2[] = "qrbnp";
int value[] = {9,5,3,3,1};

char G[maxn][maxn];

int main()
{
    for(int i = 0; i < 8; i++)
        scanf("%s",G[i]);
    int w = 0,b = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(G[i][j] == key1[k])
                    w += value[k];
                if(G[i][j] == key2[k])
                    b += value[k];
            }
        }
    }

    if(w == b) printf("Draw\n");
    if(w > b) printf("White\n");
    if(w < b) printf("Black\n");
    return 0;
}
