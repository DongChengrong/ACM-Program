#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,ans,test=1,k;
    while(cin>>n && n>0)
    {
        ans=0;
        k=1;
        while(k<n) { k*=2; ans++;}
        printf("Case %d: %d\n",test++,ans);
    }
    return 0;
}
