#include<stdio.h>
#include<string.h>
int main()
{
    char a[20];
    int c,q=1;
    gets(a);
    while((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            printf("%c",q?'¡±':'¡°');
            q=!q;
        }
        else
            printf("%c",c);
    }
    return 0;
}
