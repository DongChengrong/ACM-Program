#include<cstdio>
#include<string>
using namespace std;

const int maxn=100000;

void solve(int a,int b)
{
    string str;
    int i,start,end;
    int mark[maxn]={0};
    printf("%d/%d = %d.",a,b,a/b);
    a%=b; mark[a]=1;
    for(i=2;;i++)
    {
        a*=10; str.push_back(a/b+'0'); a%=b;
        if(mark[a]) break;
        else mark[a]=i;
    }
    end=i; start=mark[a];
    for(i=0;i<50 && i<end-1;i++)
    {
        if(i==start-1) printf("(");
        printf("%c",str[i]);
    }
    if(end-start>=50) printf("...");
    printf(")\n");
    printf("   %d = number of digits in repeating cycle\n",end-start);
}

//重装系统就是好
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        solve(a,b);
        printf("\n");
    }
    return 0;
}
