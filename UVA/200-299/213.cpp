#include<cstdio>
#include<cstring>
using namespace std;

char code[10][150];

char readchar()
{
    char c;
    c=getchar();
    while(1)
    {
        if(c=='\n' || c=='\r') c=getchar();
        else return c;
    }
}

int readint(int len)
{
    int i=0,sum=0;
    for(int i=0;i<len;i++)
    {
        sum=sum*2+(readchar()-'0');
    }
    return sum;
}

void coding()
{
    char c;
    for(int i=2;;i++)
       for(int j=0;j<(1<<i)-1;j++)
       {
            c=getchar();
            if(c=='\n' || c=='\r') return;
            code[i][j]=c;
       }
}

int main()
{
    char c;
    while(c=readchar())
    {
        if(c==EOF) break;
        code[1][0]=c;
        coding();
        while(1)
        {
            int len=readint(3);
            if(len==0) break;
            while(1)
            {
                int v=readint(len);
                if(v==(1<<len)-1) break;
                printf("%c",code[len][v]);
            }
        }
        printf("\n");
    }
    return 0;
}
