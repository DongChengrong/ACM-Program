#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 110000

int n, m;
int dir[N];
string name[N];

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            cin >> dir[i] >> name[i];
        }
        int index = 0;
        for (int i = 0; i < m; ++i) {
            //cout << name[index] << '\n';
            int c, z;
            cin >> c >> z;
            if (!dir[index]) c = !c;
            if (c == 0) {
                index = (index + z) % n;
            } else if (c == 1) {
                index = (index + n - z) % n;
            }
        }
        cout << name[index] << '\n';
    }
    return 0;
}
