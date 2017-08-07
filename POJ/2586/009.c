#include<stdio.h>
int slove(int s,int d)
{
    int i;
    int ok=1;
    int sum;
    if(10*s-2*d<0)
        ok=0;
    for(i=1;i<=5;i++)
    {
        if((5-i)*s-i*d<0)
            break;
    }
    if(i==4)
        sum=(12-2*i-1)*s-(i*2+1)*d;
    else if(i==5)
        sum=-12*d;
    else
        sum=(12-2*i)*s-i*2*d;
    if(sum<0)
        ok=0;
    if(ok)
        printf("%d\n",sum);
    else
        printf("Deficit\n");
    return ok;
}
int main()
{
    int s,d;
    while(~scanf("%d%d",&s,&d) )
    {
        slove(s,d);
    }
    return 0;
}
