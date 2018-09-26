#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            int tmp; cin >> tmp;
            if (tmp) flag = 1;
        }
        if (flag) puts("HARD");
        else puts("EASY");
    }
    return 0;
}
