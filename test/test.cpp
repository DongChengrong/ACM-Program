#include<stdio.h>

int main()
{
    int a[5] = {1,10,100};
    int *p = &a[0];
    printf("%d\n",*p++);
    printf("%d\n",*p);
    return 0;
}
