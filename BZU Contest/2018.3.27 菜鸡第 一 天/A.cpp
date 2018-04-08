#include<stdio.h>

int main()
{
    int a[10],sum = 0;
    for(int i = 0; i < 5; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < 5; i++)
        sum += a[i];
    if(sum % 5 == 0) printf("%d\n",sum / 5);
    else printf("-1\n");
    return 0;
}
