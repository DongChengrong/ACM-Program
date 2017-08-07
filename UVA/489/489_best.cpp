#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
int alp[30],count,win,lose,total;
char s1[maxn],s2[maxn];

void judge(char c)
{
    if(alp[c-'a'])
    {
        alp[c-'a']=0;
        total--;
        if(!total) win=1;
    }
    else
    {
        count++;
        if(count==7) lose=1;
    }
}

int main()
{
    int T;
    while(scanf("%d",&T)==1 && T!=-1)
    {
        scanf("%s",s1);
        win=lose=total=count=0;
        memset(alp,0,sizeof(alp));
        for(int i=0;i<strlen(s1);i++)
        {
            if(!alp[s1[i]-'a'])
            {
                total++;
                alp[s1[i]-'a']=1;
            }
        }
        scanf("%s",s2);
        for(int i=0;i<strlen(s2);i++)
        {
            if(win || lose) break;
            judge(s2[i]);
        }
        printf("Round %d\n",T);
        if(lose) printf("You lose.\n");
        else
        {
            if(win) printf("You win.\n");
            else printf("You chickened out.\n");
        }
    }
    return 0;
}
