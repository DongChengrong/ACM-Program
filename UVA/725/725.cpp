#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int n;
int number[10];
bool id[10];
bool ok;

bool judge(long i,long j)
{
    if(i>=100000 || j>=100000) return false;
    int z;
    for(int l=4;l>=0;l--)
    {
        z=j%10;
        id[z]=true;
        number[l]=z;
        j=j/10;
    }
    for(int l=9;l>=5;l--)
    {
        z=i%10;
        id[z]=true;
        number[l]=z;
        i=i/10;
    }
    for(int l=0;l<10;l++) if(!id[l]) return false;
    return true;
}

void print()
{
    int l;
    ok=true;
    for(l=0;l<5;l++) cout<<number[l];
    cout<<" / ";
    while(l<10) cout<<number[l++];
    cout<<" = "<<n;
    cout<<endl;
}

int main()
{
    while(cin>>n && n)
    {
        memset(number,0,sizeof(number));
        ok=false;
        for(long i=1000;i<100000;i++)
        {
            memset(id,false,sizeof(id));
            long j=i*n;
            if(judge(i,j)) print();
        }
        if(!ok) cout<<"There are no solutions for "<<n<<"."<<endl<<endl;
        else cout<<endl;
    }
    return 0;
}
