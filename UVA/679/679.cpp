#include<cstdio>
using namespace std;

int main()
{
    int test;
    while(~scanf("%d",&test) && test!=-1)
    {
        int n,D;
        for(int i=0;i<test;i++)
        {
            int l=1,d=1;
            scanf("%d%d",&D,&n);
            while(d!=D)
            {
                if(n%2)
                {
                    l*=2;
                    n=(n+1)/2;
                }
                else
                {
                    l=l*2+1;
                    n=n/2;
                }
                d++;
            }
            printf("%d\n",l);
        }
    }
}
