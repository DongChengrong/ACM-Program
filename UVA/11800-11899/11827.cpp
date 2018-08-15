//GCDÀ„∑®
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 110

int a[N];

int main() {
    int T;
    scanf("%d", &T); getchar();
    while (T--) {
        int MAX = -1, n = 0, x;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> x) a[n++] = x;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                MAX = max(MAX, __gcd(a[i], a[j]));
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
}
