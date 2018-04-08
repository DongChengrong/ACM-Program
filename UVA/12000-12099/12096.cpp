#include<cstdio>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

char order[10];
typedef set<int> Set;
map<Set,int> m;
vector<Set> v;
stack<int> sta;

int ID(Set s)
{
    if(m.count(s)) return m[s];
    v.push_back(s);
    return m[s]=v.size()-1;
}

int main()
{
    int Test;
    scanf("%d",&Test);
    while(Test--)
    {
        int O;
        scanf("%d",&O);
        while(O--)
        {
            scanf("%s",order);
            if(order[0]=='P') sta.push(ID(Set()));
            else if(order[0]=='D') sta.push(sta.top());
            else
            {
                Set x1=v[sta.top()]; sta.pop();
                Set x2=v[sta.top()]; sta.pop();
                Set x;
                if(order[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
                if(order[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
                if(order[0]=='A') { x=x2; x.insert(ID(x1));  }
                sta.push(ID(x));
            }
            printf("%d\n",v[sta.top()].size());
        }
        printf("***\n");
    }
    return 0;
}
