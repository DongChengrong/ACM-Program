#include<cstdio>

int main()
{
    int max,min,temp;;
    scanf("%d",&temp);
    min=max=temp;
    for(int i=0;i<4;i++)
    {
        scanf("%d",&temp);
        if(temp>max) max=temp;
        if(temp<min) min=temp;
    }
    printf("%d %d\n",min,max);
    return 0;
}
