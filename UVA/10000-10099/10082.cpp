#include<cstdio>
#include<cstring>
using namespace std;

char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    char c;
    while((c=getchar()) && c!=EOF)
    {
        int pos=-1;
        for(int i=0;s[i];i++) if(s[i]==c) { pos=i; break; }
        if(pos==-1) putchar(c);
        else putchar(s[pos-1]);
    }
}
