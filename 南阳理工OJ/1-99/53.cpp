#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int MAX = -10000,index = 1;
        for(int i = 1; i <= 7; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x = x + y;
            if(MAX < x)
            {
                MAX = x; index = i;
            }
        }
        if(MAX > 8) printf("%d\n",index);
        else printf("0\n");
    }

}
