#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int x;
    int y;
}A[200];
int cmp(struct node a,struct node b)
{
    return a.x<b.x;
}
void save(int x,int y,int i)
{
    if(x>y)
    {
        A[i].x=y;
        A[i].y=x;
    }
    else
    {
        A[i].x=x;
        A[i].y=y;
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            save(x,y,i);
        }
        sort(A,A+n-1,cmp);
        int j=1;
        for(int i=0;i<n-1;i++)
        {
           if(A[i+1].x%2) if(A[i].y>=A[i+1].x) j++;
           if(!(A[i+1].x%2)) if(A[i].y+1>=A[i+1].x) j++;
        }
        printf("%d\n",j*10);
    }
    return 0;
}
