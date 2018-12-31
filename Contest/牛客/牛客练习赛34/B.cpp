#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
unordered_map<int, int> ma;
 
int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        sum += x;
        ma[x]++;
    }
    int x = abs(sum);
    if (x & 1) {
        puts("-1");
        return 0;
    }
    sum = sum / 2;
    if (ma[sum] == 0) puts("-1");
    else printf("%d\n", ma[sum]);
    return 0;
}