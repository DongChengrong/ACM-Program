#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int T = 1;
    int p,e,l,d;
    while(scanf("%d%d%d%d",&p,&e,&l,&d) == 4 &&  p != -1)
    {
        p = p % 23; e = e % 28; l = l % 33;
        for(int i = d + 1; ; i++)
            if( i % 23 == p && i % 28 == e && i % 33 == l)
            {
                printf("Case %d: the next triple peak occurs in %d days.\n",T++, i - d);
                break;
            }
    }
    return 0;
}
