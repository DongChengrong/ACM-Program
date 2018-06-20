#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define N 20
#define INF 0x3f3f3f3f
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

int n;
int a[N];
string line;

void slove() {
    int ans = INF;
    while (a[0] == 0) next_permutation(a, a + n);    //去除前导0
    do {
        int mid = n / 2;
        int pre = 0, suf = 0;
        if (a[mid] == 0) continue;   //去除前导0
        _for (i, 0, mid) pre = pre * 10 + a[i];
        _for (i, mid, n) suf = suf * 10 + a[i];
        ans = min(abs(pre - suf), ans);
    } while (next_permutation(a, a + n));
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d",&T); getchar();
    while (T--) {
        n = 0;
        getline(cin, line);
        stringstream buf(line);
        while (buf >> a[n]) ++n;
        if (n == 1) printf("%d\n",a[0]);
        else if (n == 2) printf("%d\n",abs(a[0] - a[1]));
        else slove();
    }
    return 0;
}
