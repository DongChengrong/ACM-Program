//递归，看着挺复杂，实际上挺简单的
#include <stdio.h>

void dfs(int x) {
    if (!x) { printf("0"); return; }
    int flag = 0;
    for (int i = 16; i >= 0; --i) {
        if (x >= (1 << i)) {
            if (flag) printf("+");
            else flag = 1;

            printf("2");
            if (i != 1) { printf("("); dfs(i); printf(")"); }
            x -= (1 << i);
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        dfs(n);
    }
    return 0;
}
