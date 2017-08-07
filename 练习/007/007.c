#include<stdio.h>
#include<string.h>

char str[100],str2[100];
int left,chance;
int win,lose;

void judge(char c)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==c)
        {
            str[i]=' ';
            left--;
        }
        else
            chance--;
        if(!left)
        {
            win=1;
            break;
        }
        if(!chance)
        {
            lose=1;
            break;
        }
    }
}

int main()
{
    int cnt;
    int i;
    while(~scanf("%d",&cnt) && cnt!=-1)
    {
        win=lose=0;
        chance=7;
        scanf("%s",str);
        scanf("%s",str2);
        printf("Round %d\n",cnt);
        left=strlen(str);
        for(i=0;i<strlen(str2);i++)
            judge(str2[i]);
        if(win)
            printf("You Win!\n");
        else if(lose)
            printf("Tou Lose\n");
        else
            printf("You chickened out\n");
    }
    return 0;
}
