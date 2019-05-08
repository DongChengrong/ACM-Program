#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define N 33

int n;
int a[N], b[N];

int main() {
    //ios_base::sync_with_stdio(false);
    string str;
    while (getline(cin, str)) {
        n = 0;
        cout << str << '\n';
        stringstream ss(str);
        while (ss >> a[n]) { b[n] = a[n]; n = n + 1; }
        sort(b, b + n);
        for (int i = n - 1; i > 0; --i) {
            int target = b[i], j;
            for (j = i; j >= 0; --j) if (a[j] == target) break;
            if (i == j) continue;
            if (j != 0) {
                reverse(a, a + j + 1);
                printf("%d ", n - j);
            }
            reverse(a, a + (i + 1));
            printf("%d ", n - i);
        } puts("0");
    }
    return 0;
}
