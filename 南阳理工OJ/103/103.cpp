#include<stdio.h>
#include<string.h>

const int maxn = 1000 + 10;
char a[maxn],b[maxn];
int c[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    for(int test = 1; test <= T; test++)
    {
        int len1,len2,len = 0;


        scanf("%s%s",a,b);

        int r = 0;
        len1 = strlen(a) - 1; len2 = strlen(b) - 1;
        for(int i = len1, j = len2;i >= 0 || j >= 0; i--,j--)
        {
            int v_a,v_b;

            if(i < 0) v_a = 0;
            else v_a = a[i] - '0';

            if(j < 0) v_b = 0;
            else v_b = b[j] - '0';

            int tmp = (v_a + v_b + r);
            c[len] = tmp % 10;
            r = tmp / 10;
            len++;
        }

        printf("Case %d:\n",test);
        printf("%s + %s = ",a,b);

        if(r > 0) printf("%d",r);
        for(int i = len - 1; i >= 0; i--)
            printf("%d",c[i]);
        printf("\n");
    }
    return 0;
}
