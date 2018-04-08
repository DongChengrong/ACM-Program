#include<stdio.h>
#include<string.h>
char *maya[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char *tzo[20]={ "imix",  "ik", "akbal", "kan",  "chicchan",  "cimi",  "manik", "lamat",  "muluk", "ok", "chuen", "eb",  "ben", "ix", "mem",  "cib", "caban", "eznab", "canac", "ahau"};
int totalDate(int d,char *m,int y)
{
    int date=0;
    int i;
    for(i=0;i<19;i++)
    {
        if(!strcmp(maya[i],m))
            break;
    }
    date=i*20+d+y*365;
    return date;
}
void solve(int date)
{
    int i;
    int d,y;
    y=date/260;
    d=date%13+1;
    i=date%20;
    printf("%d %s %d\n",d,tzo[i],y);
}
int main()
{
    int n,date;
    char s[10];
    int d,y;
    scanf("%d",&n);
    printf("%d\n",n);
    while(n)
    {
        scanf("%d. %s %d",&d,s,&y);
        date=totalDate(d,s,y);
        solve(date);
        n--;
    }
    return 0;
}
