#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=20;
int num[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int ok=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&num[i]);
        for(int i=0;i<1000;i++)
        {
            int flag=1; int a=num[0];
            for(int j=0;j<n-1;j++){ num[j]=abs(num[j]-num[j+1]); if(num[j]!=0) flag=0; }
            num[n-1]=abs(num[n-1]-a);
            if(num[n-1]!=0) flag=0;
            if(flag) { ok=1; break; }
        }
        if(ok) printf("ZERO\n");
        else printf("LOOP\n");
    }
    return 0;
}
