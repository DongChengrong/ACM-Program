#include<cstdio>
#include<map>
#include<sstream>
using namespace std;

typedef pair<int,int> P;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        map<P,int> m;
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            P p=make_pair(y,x);
            if(m.count(p)) { m[p]--; if(m[p]==0) m.erase(p); }
            else { p=make_pair(x,y); if(!m.count(p)) m[p]=1; else m[p]++; }
        }
        if(!m.size()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
