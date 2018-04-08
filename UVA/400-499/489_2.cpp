#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100;
char s1[maxn],s2[maxn];
int chance,left;
bool win,lose;

void judge(char c)
{
    int ok=0;
    for(int i=0;i<strlen(s1);i++)
        if(s1[i]==c) { s1[i]=' '; ok=1; left--; }
    if(!ok) chance--;
    if(!chance) lose=true;
    if(!left) win=true;
}

int main()
{
    int T;
    while(scanf("%d",&T)==1 && T!=-1)
    {
        printf("Round %d\n",T);
        scanf("%s%s",s1,s2);
        left=strlen(s1);
        chance=7;
        win=lose=false;
        for(int i=0;i<strlen(s2);i++)
        {
            if(win || lose) break;
            judge(s2[i]);
        }
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}
