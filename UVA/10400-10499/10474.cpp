#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
int N,Q;
int Mar[maxn],ques[maxn];

int main()
{
    int Test=1;
    while(scanf("%d %d",&N,&Q)==2 && N)
    {
        printf("CASE# %d:\n",Test++);
        for(int i=0;i<N;i++) scanf("%d",&Mar[i]);
        for(int i=0;i<Q;i++) scanf("%d",&ques[i]);
        sort(Mar,Mar+N);
        for(int i=0;i<Q;i++)
        {
            int pos=lower_bound(Mar,Mar+N,ques[i])-Mar;
            if(Mar[pos]==ques[i]) printf("%d found at %d\n",ques[i],pos+1);
            else printf("%d not found\n",ques[i]);
        }
    }
    return 0;
}
