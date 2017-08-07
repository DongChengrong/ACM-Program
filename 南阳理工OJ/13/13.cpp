#include<iostream>
using namespace std;

const int maxn=30;
long long int fib[maxn];

void getFib(int n)
{
    fib[n]=fib[n-1]+fib[n-2];
}

int main()
{
    int m,n;
    cin>>m;
    fib[0]=fib[1]=1;
    for(int i=2;i<20;i++)
        getFib(i);
    while(m--)
    {
        cin>>n;
        cout<<fib[n-1]<<endl;
    }
    return 0;
}
