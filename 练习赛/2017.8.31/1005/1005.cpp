#include<stdio.h>

const int maxn = 100000 + 100;
int a[maxn];

int main()
{
    int n,p;
    while(scanf("%d %d",&n,&p) == 2)
    {
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        for(int i = 1;i <= p;i++)
        {
            int k,s1,s2,s3;
            scanf("%d",&k);
            if(k == 1) s1 = s2 = s3 = a[2];
            else s1 = s2 = s3 = a[1];
            for(int j = k == 1?3:2;j <= n;j++)
            {
                if(k == j) continue;
                s1 = s1 & a[i];
                s2 = s2 | a[i];
                s3 = s3 ^ a[i];
            }
            printf("%d %d %d\n",s1,s2,s3);
        }
    }
    return 0;
}
