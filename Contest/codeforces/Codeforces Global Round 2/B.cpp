#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

#define N 11000

typedef long long ll;

int check(vector<int> vec, int k, int h) {
    ll tmp = 0;
    sort(vec.begin(), vec.begin() + k);
    for (int i = k - 1; i >= 0; i -= 2){
        tmp += (ll)vec[i];
    }
    return tmp <= (ll)h;
}

int main() {
    int n, h; scanf("%d%d", &n, &h);
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        vec.push_back(x);
    }
    int l = 0, r = n;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (check(vec, mid, h)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);;
    return 0;
}
