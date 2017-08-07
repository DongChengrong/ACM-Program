#include<cstdio>
#include<algorithm>
using namespace std;

long long cycle(long long n){
    int len=1;
    if(n==1) return len;
    while(n!=1){
        if(n%2) n=3*n+1;
        else n/=2;
        len++;
    }
    return len;
}

int main(){
    long long i,j;
    while(scanf("%lld %lld",&i,&j)==2){
        long long left=min(i,j);
        long long right=max(i,j);
        long long maxn=cycle(left);
        for(long long k=left+1;k<=right;k++)
            maxn=max(maxn,cycle(k));
        printf("%lld %lld %lld\n",i,j,maxn);
    }
}
