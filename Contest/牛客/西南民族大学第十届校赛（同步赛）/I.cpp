#include <stdio.h>

void print(int i, char c) {
    for (int j = 0; j < i; ++j) printf("%c", c);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n - 1; ++i) {
            print(i, ' '); print(n, '*'); puts("");
        }
        print(n - 1, ' '); print(n, '*'); puts("");
        for (int i = n - 2; i >= 0; --i) {
            print(i, ' '); print(n, '*'); puts("");
        }
    }
    return 0;
}
