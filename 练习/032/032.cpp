#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        if(n & 1) printf("%d ������\n",n);
        else printf("%d ��ż��\n",n);
    }
}
