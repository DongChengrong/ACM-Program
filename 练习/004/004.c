#include<stdio.h>
#include<string.h>

void action(int n,int cur,char *a,char *b)
{
    int i;
    if(cur==n)
    {
        b[cur]='\0';
        printf("%s\n",b);
        return;
    }
    else
    {
        for(i=0;i<strlen(a);i++)
        {
            b[cur]=a[i];
            action(n,cur+1,a,b);
        }
    }
}

int main()
{
    char a[20];
    char b[5];
    gets(a);
    action(3,0,a,b);
    return 0;
}
