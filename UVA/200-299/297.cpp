#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=2000;
const int len=32;
int buf[len][len],cnt;
char s[maxn];

void draw(char *s,int &p,int r,int c,int w)
{
    char cc=s[p++];
    if(cc=='p')
    {   //依次绘画四个子树
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }else if(cc=='f')
    {
        for(int i=r;i<r+w;i++)
        {
            for(int j=c;j<c+w;j++)
            {
                if(!buf[i][j])
                {
                    buf[i][j]=1;
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        memset(buf,0,sizeof(buf));
        for(int i=0;i<2;i++)
        {
            int p=0;
            scanf("%s",s);
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}
