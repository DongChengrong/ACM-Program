#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int leaf, circle;

void get_circle(int &leaf, int &circle) {
    leaf = 2, circle = 1;
    while (leaf < n) {
        leaf *= 2;
        ++circle;
    }
}

int get(int a, int b) {
    if (a > b) swap(a, b);
    int l = 0, r = leaf, k = circle;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a <= mid && b > mid) return k;
        else if (b <= mid) {
            --k; r = mid;
        } else if (a > mid) {
            --k; l = mid;
        }
    }
}

int main() {
    while (scanf("%d%d%d",&n,&a,&b) == 3) {
        get_circle(leaf, circle);
        int k = get(a, b);
        if (k == circle) puts("Final!");
        else printf("%d\n",k);
    }
    return 0;
}
