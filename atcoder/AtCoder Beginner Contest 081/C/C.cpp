#include<stdio.h>
#include<math.h>
#include<map>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 200000 + 10;

struct Node
{
    int x, num;
    Node(){}
    Node(int x, int num)
    {
        this->x = x;
        this->num = num;
    }
    bool operator < (const Node & a) const {
        return this-> num < a.num;
    }
}a[maxn];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k) )
    {
        map<int, int> m;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            if(m.count(x) == 0)
            {
                m[x] = cnt;
                a[cnt++] = Node(x,1);
            }
            else a[m[x]].num++;
        }

        sort(a, a+cnt);

        int count = 0;
        int i = 0;
        while(cnt > k)
        {
            cnt--;
            count += a[i++].num;
        }
        cout << count << endl;
    }
    return 0;
}
