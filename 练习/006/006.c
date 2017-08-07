#include<stdio.h>
int count(int i)
{
    int cn=1;
    while(i!=1)
    {
        if(i%2)
            i=3*i+1;
        else
            i=i/2;
        cn++;
    }
    return cn;
}
int main()
{
    int i,j,z,max;
    while(scanf("%d%d",&i,&j)==2)
    {
        max=0;
        if(i<j)
        {
            for(z=i;z<=j;z++)
            {
                max=max>count(z)?max:count(z);
            }
        }
        else
        {
            for(z=j;z<=i;z++)
            {
                max=max>count(z)?max:count(z);
            }
        }
        printf("%d %d %d\n",i,j,max);
    }
    return 0;
}
