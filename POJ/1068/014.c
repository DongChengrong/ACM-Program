#include<stdio.h>
int num,cur;
char a[200];

void pushPar(int b)
{
    int i;
    i=b-num;
    num=b;
    while(i--)
    {
        a[cur]='(';
        cur++;
    }
    a[cur]=')';
    cur++;
}

void popNum()
{
    int rl,ll;
    int i;
    rl=1;
    ll=0;
    i=cur-2;
    while(rl!=ll)
    {
        if(a[i]=='(')
            ll++;
        else
           rl++;
        i--;
    }
    printf("%d ",rl);
}

int main()
{
    int t,n,l;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        cur=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&l);
            pushPar(l);
            popNum();
        }
        printf("\n");
    }
    return 0;
}
