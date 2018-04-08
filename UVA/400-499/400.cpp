#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100+10;
const int colcha=60;
string s[maxn];

void print(string ss,int len,char a)
{
    cout<<ss;
    for(int i=0;i<len-ss.length();i++) putchar(a);
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int M=0;
        printf("------------------------------------------------------------\n");
        for(int i=0;i<n;i++)
        { cin>>s[i]; int l=s[i].length(); M=max(M,l); }
        int cols=(colcha-M)/(M+2)+1;
        int rows=(n-1)/cols+1;
        sort(s,s+n);
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                int id=c*rows+r;
                if(id<n) print(s[id],c==cols-1?M:M+2,' ');
            }
            printf("\n");
        }
    }
    return 0;
}
