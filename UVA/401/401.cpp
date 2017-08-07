#include<cstdio>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;

const char* S[]={" -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string."," -- is a mirrored palindrome."};
char b[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char replace(char c)
{
    if(isalpha(c)) return b[c-'A'];
    else return b[c-'1'+26];
}

int main()
{
    char s1[100];
    while(scanf("%s",s1)==1)
    {
        int p,q;
        p=q=1;
        int l=strlen(s1);
        for(int i=0;i<(l+1)/2;i++)  //因为有镜像所以一定要+1，当奇数时判断该数镜像后是否等于它本身
        {
            if(s1[i]!=s1[l-i-1]) p=0;
            if(s1[i]!=replace(s1[l-i-1])) q=0;
        }
        printf("%s%s\n\n",s1,S[p+q*2]);
    }
    return 0;
}
