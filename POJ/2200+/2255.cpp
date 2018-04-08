#include<cstdio>
#include<cstring>
void print(int n,char *s1,char *s2)
{
    int i;
    if(n<=0) return;
    for(i=0;i<strlen(s2);i++) if(s1[0]==s2[i]) break;
    print(i,s1+1,s2);
    print(n-i-1,s1+i+1,s2+i+1);
    printf("%c",s1[0]);
}
int main()
{
    char s1[50],s2[50];
    while(~(scanf("%s%s",s1,s2)))
    {
        print(strlen(s1),s1,s2);
        printf("\n");
    }
    return 0;
}
