#include<stdio.h>
#include<string.h>

const int maxn = 100 + 10;
char s[maxn];

int main()
{
    int a,b,n;
    while(scanf("%s",s) == 1)
    {
        a = b = 0;
        n = strlen(s);
        for(int i = 0; i < n; i++)
            if(s[i] == '0')
            {
                b++;
                if(s[(i + 1) % n] == '0') a++;
            }
        int k1, k2;
        k1 = a * n;
        k2 = b * b;
        if(k1 < k2) printf("ROTATE\n");
        else if(k1 > k2) printf("SHOOT\n");
        else printf("EQUAL\n");
    }
    return 0;
}
