#include <stdio.h>
#include <stdlib.h>


int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        int x = 0;
        for(int i = m; i <= n; i++)
        {
            int c=i;
            int s=0;
            while(c>0)
            {
                int a = c%10;
                s = s + a * a * a;
                c = c / 10;
            }
            if(i==s)
            {
                if(!x) printf("%d",i);
                else printf(" %d",i);
                x=1;
            }
        }
        if(x==0) printf("no");
        printf("\n");
    }
}
