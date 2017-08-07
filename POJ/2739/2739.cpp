#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int sum;
int tot;
int id[10000+5];

int isPrime(int n)
{
    int m;
    if(n<=1) return 0;
    m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++)
        if(n%i==0) return 0;
    return 1;
}

int next_prime(int cur)
{
    for(int i=cur+1;i<=sum;i++) if(id[i]) return i;
    return 0;
}

void my_search(int cur,int cursum)
{
    if(cursum==sum) { tot++; return; }
    if(cursum>sum) return;
    for(int i=cur+1;i<=sum;i++)
    {
        if(cur==1 && id[i]) my_search(i,cursum+i);
        else if(id[i] && next_prime(cur)==i) my_search(i,cursum+i);
        else if(id[i] && next_prime(cur)!=i) return;
    }
}

int main()
{
    while(cin>>sum && sum)
    {
        tot=0;
        for(int i=0;i<=sum;i++) id[i]=isPrime(i);
        my_search(1,0);
        cout<<tot<<endl;
    }
    return 0;
}
