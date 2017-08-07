#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=20000+20;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,ok=1;
        double ver;
        vector<int> v[maxn],v1;
        scanf("%d",&N);
        while(N--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            v[y+10000].push_back(x);
            v1.push_back(y+10000);
        }
        for(int i=0;i<v1.size();i++)
            sort(v[v1[i]].begin(),v[v1[i]].end());
        int y=v1[0];
        if(v[y].size()%2) { int pos=v[y].size()/2; ver=v[y][pos]; }
        else { int pos=v[y].size()/2; ver=(v[y][pos-1]+v[y][pos])/2; }
        for(int i=0;i<v1.size();i++)
        {
            if(!ok) break;
            int y=v1[i];
            int front,rear;
            double cnt;
            if(v[y].size()%2)
            {
                rear=v[y].size()/2;
                cnt=v[y][rear];
                front=rear-1; rear++;
            }
            else
            {
                rear=v[y].size()/2; front=rear-1;
                cnt=(v[y][front]+v[y][rear])/2;
            }
            if(cnt!=ver) { ok=0; break; }
            while(front>=0 && rear<v[y].size())
            {
                cnt=(v[y][front--]+v[y][rear++])/2;
                if(cnt!=ver) { ok=0; break; }
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
