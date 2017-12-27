#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        map<int, int> m;
        while(n--)
        {
            int num;
            scanf("%d",&num);
            m[num]++;
        }

        map<int, int> ::iterator it = m.begin();
        int MAX = it->first;
        int cnt = it->second;
        it++;

        while(it != m.end())
        {
            if(it->second > cnt)
            {
                cnt = it->second;
                MAX = it->first;
            }
            it++;
        }
        printf("%d\n",MAX);
    }
    return 0;
}
