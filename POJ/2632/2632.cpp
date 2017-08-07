#include<stdio.h>
#include<string.h>

int ok;
int A,B;
int N,M;
char c[]={'L','F','R'};
char d[]="NWSE";

struct Node
{
    int x,y;
    char c;
}r[110];

void judge(int id)
{
    if(r[id].x<1 || r[id].x>A || r[id].y<1 || r[id].y>B)
    {
        ok=1;
        printf("Robot %d crashes into the wall\n",id);
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(i==id) continue;
        if(r[id].x==r[i].x && r[id].y==r[i].y)
        {
            ok=1;
            printf("Robot %d crashes into robot %d\n",id,i);
            return;
        }
    }
}

void move(int n,char dir,int id)
{
    char c=r[id].c;
    int i=strchr(d,c)-d;
    if(dir=='F')
    {
        if(c=='N') { for(int k=0;k<n;k++) { if(ok) return;  r[id].y++; judge(id); } return;}
        else if(c=='S') { for(int k=0;k<n;k++) { if(ok) return;  r[id].y--; judge(id); }  return; }
        else if(c=='W') { for(int k=0;k<n;k++) { if(ok) return;  r[id].x--; judge(id); } return; }
        else if(c=='E') { for(int k=0;k<n;k++) { if(ok) return;  r[id].x++; judge(id); }  return; }
    }
    else if(dir=='L')
    {
        for(int j=0;j<n;j++)
        {
            i++;
            i%=4;
        }
        r[id].c=d[i];
        return;
    }
    else
    {
        for(int j=0;j<n;j++)
        {
            i=i+3;
            i%=4;
        }
        r[id].c=d[i];
        return;
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {
        scanf("%d%d",&A,&B);
        scanf("%d%d",&N,&M);
        for(int j=1;j<=N;j++) scanf("%d %d %c",&r[j].x,&r[j].y,&r[j].c);
        ok=0;
        for(int j=1;j<=M;j++)
        {
            int n,id;
            char ch;
            scanf("%d %c %d",&id,&ch,&n);
            if(ok) continue;
            move(n,ch,id);
        }
        if(!ok) printf("OK\n");
    }
    return 0;
}
