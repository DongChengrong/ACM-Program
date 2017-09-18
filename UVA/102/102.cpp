#include<stdio.h>

const int INF = 1 << 30;
const char ch[] = "BCG";
const int W[6][3] = { {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0} };
int B[3][5];

void swap(int i)
{
    int temp = B[i][1];
    B[i][1] = B[i][2];
    B[i][2] = temp;
}

int main()
{
    while(scanf("%d",&B[0][0]) == 1)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i + j == 0) continue;
                scanf("%d",&B[i][j]);
            }
            swap(i);
        }

        unsigned Min = 0xffffffff, id;
        for(int i = 0; i < 6; i++)
        {
            int temp = 0;
            for(int j = 0; j < 3; j++)
            {
                for(int k = 0; k < 3; k++)
                    if(W[i][j] != k)
                        temp += B[j][k];
            }
            if(temp < Min) Min = temp, id = i;
        }
        printf("%c%c%c %d\n",ch[W[id][0]],ch[W[id][1]],ch[W[id][2]],Min);
    }
    return 0;
}
