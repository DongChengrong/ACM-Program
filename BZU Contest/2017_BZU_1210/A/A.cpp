#include<stdlib.h>
#include<stdio.h>

int main()
{
    int l,r;
    while(scanf("%d%d",&l,&r) == 2)
    {
        int c = abs(l - r);
        if(c <= 1 && (l != 0 || r != 0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
