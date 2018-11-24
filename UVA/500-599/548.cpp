#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define N 11000
#define INF 0x3f3f3f3f

int n, root, MIN, leaf;
int l[N], r[N];
int a1[N], a2[N];

void convert(string s, int a[]) {
    n = 0;
    stringstream ss(s);
    while (ss >> a[n++]); --n;
}

int build(int *a1, int *a2, int n) {
    if (n == 0) return 0;
    int mid = a2[n - 1], i;
    for (i = 0; i < n; ++i) if (mid == a1[i]) break;
    l[mid] = build(a1, a2, i); r[mid] = build(a1 + i + 1, a2 + i, n - i - 1);
    return mid;
}

void dfs(int u, int sum) {
    if (sum > MIN) return;
    sum += u;

    if (!l[u] && !r[u]) {
        if (sum == MIN) {
            if (u < leaf) leaf = u;
        } else if (sum < MIN) {
            MIN = sum; leaf = u;
        }
    } else {
        if (l[u]) dfs(l[u], sum);
        if (r[u]) dfs(r[u], sum);
    }
}

int main() {
    string s;
    while (getline(cin, s)) {
        convert(s, a1);
        getline(cin, s);
        convert(s, a2);
        build(a1, a2, n);
        root = a2[n - 1];
        leaf = MIN = INF;
        dfs(root, 0);
        printf("%d\n", leaf);
    }
    return 0;
}
