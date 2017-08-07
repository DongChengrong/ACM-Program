#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=10000+10;
int num[maxn][10];
int score[10];

void number(int n)
{
    int i=n;
    while(i)
    {
        int temp=i%10;
        num[n][temp]++;
        i/=10;
    }
}

int main()
{
    int n,t;
    scanf("%d",&t);
    memset(num,0,sizeof(num));
    for(int i=1;i<=10000;i++) number(i);
    while(t--)
    {
        memset(score,0,sizeof(score));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=9;j++)
                score[j]+=num[i][j];
        for(int i=0;i<=8;i++) printf("%d ",score[i]);
        printf("%d\n",score[9]);
    }
    return 0;
}
