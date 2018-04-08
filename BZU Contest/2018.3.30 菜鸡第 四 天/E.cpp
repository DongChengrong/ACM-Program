#include<stdio.h>
#include<map>
#include<ctype.h>
using namespace std;

typedef long long LL;

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        map<LL,LL> x,y;
        map<pair<LL,LL>,LL> xy;
        LL X,Y;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld%lld",&X,&Y);
            if(x.count(X) == 0) x[X] = 1;
            else x[X]++;
            if(y.count(Y) == 0) y[Y] = 1;
            else y[Y]++;
            if(xy.count(make_pair(X,Y)) == 0) xy[make_pair(X,Y)] = 1;
            else xy[make_pair(X,Y)]++;
        }
        LL sum = 0;
        for(map<LL,LL> ::iterator it = x.begin(); it != x.end(); it++)
            sum += it->second * (it->second - 1) / 2;
        for(map<LL,LL> ::iterator it = y.begin(); it != y.end(); it++)
            sum += it->second * (it->second - 1) / 2;
        for(map<pair<LL,LL>,LL> ::iterator it = xy.begin(); it != xy.end(); it++)
            sum -= it->second * (it->second - 1) / 2;
        printf("%lld\n",sum);
    }
    return 0;
}
