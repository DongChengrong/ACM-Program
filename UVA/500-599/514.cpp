#include<stdio.h>
#include<stack>
using namespace std;

const int maxn=1000+10;
int a[maxn];

int main()
{
    int n;
    int mark=0;
    while(scanf("%d",&n)==1 && n)
    {
        mark=0;
        while(1)
        {
            for(int i=1;i<=n;i++) { scanf("%d",&a[i]); if(a[i]==0) {mark=1; break;} }
            if(mark) break;
            int A=1,B=1;
            int ok=1;
            stack<int> s;
            while(B<=n)
            {
                if(A==a[B]){ A++; B++; }
                else if(!s.empty() && s.top()==a[B]){ B++; s.pop(); }
                else if(A<=n) { s.push(A++); }
                else { ok=0; break; }
            }
            printf("%s\n",ok?"Yes":"No");
        }
        printf("\n");
    }
    return 0;
}
