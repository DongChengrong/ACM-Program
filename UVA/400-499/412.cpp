#include <stdio.h>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 32868

int a[N];
unordered_map<int, int> ma;

int main() {
    int m;
    while (scanf("%d", &m) != EOF && m) {
        int n = 0;
        double val = 0, num = m * (m - 1) / 2;
        for (int i = 0; i < m; ++i){
            int x; scanf("%d", &x);
            if (!ma[x]) a[n++] = x;
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(a[i], a[j]) == 1) val += 1;
            }
        }
        double rat = val / num;
        if (val != 0) printf("%.6f\n", sqrt(6 / rat));
        else puts("No estimate for this data set.");
    }
    return 0;
}
/*
5
2
3
4
5
6
2
13
39
0
*/
