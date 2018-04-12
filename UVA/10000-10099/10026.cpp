/*
贪心算法，用到了最优子结构的性质
因为贪心算法是由局部最优解构成的，所以我们可以分解到只剩两个数的时候，此时他们的先后顺序不会因为后面新加入的节点而改变
所以他们实际上是有一个大小或者说是优先级，我们让优先级高的在上面，拍一下序就好了
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 11000

struct Node {
    int s,t,id;
    bool operator < ( const Node &a) {
        if (t * a.s != a.t * s)
            return  t * a.s < s * a.t;
        else
            return id < a.id;
    }
};

Node a[N];

int main() {
    int T, n;
    bool flag = false;
    scanf("%d",&T);
    while (T--) {

        if (flag) printf("\n");
        else flag = true;

        scanf("%d",&n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d",&a[i].t, &a[i].s);
            a[i].id = i;
        }

        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; ++i) {
            printf("%d%c",a[i].id, i == n ? '\n' : ' ');
        }
    }
    return 0;
}
