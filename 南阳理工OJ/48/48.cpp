#include<cstdio>
#include<set>
using namespace std;

int main()
{
    int n,buf;
    set<int> s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&buf);
        s.insert(buf);
    }
    printf("%d\n",s.size());
    set<int> :: iterator it;
    it=s.begin(); printf("%d",*it); it++;
    while(it!=s.end())
    {
        printf(" %d",*it);
        it++;
    }
    printf("\n");
    return 0;
}
