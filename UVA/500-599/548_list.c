#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 110000
#define INF 0x3f3f3f3f

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node, *Tree;

int n, leaf, MIN;
Tree root;
int a[2][N];

int read() {
    int i; char c;
    for (i = 0; i < 2; ++i) {
        a[i][n = 0] = -1;
        while (scanf("%d%c", &a[i][n++], &c) != EOF) if (c == '\n') break;
        if (a[i][0] == -1) return 0;
    }
    return 1;
}

Tree build(int *a1, int *a2, int n) {
    if (n == 0) return NULL;
    int i, mid = a2[n - 1];
    Tree root = (Tree)malloc(sizeof(Node));
    root->data = mid;
    for (i = 0; i < n; ++i) if (mid == a1[i]) break;
    root->left = build(a1, a2, i);
    root->right = build(a1 + i + 1, a2 + i, n - i - 1);
    return root;
}

void dfs(Tree root, int sum) {
    if (sum > MIN) return;
    sum += root->data;
    if (root->left == NULL && root->right == NULL) {
        if (sum < MIN || (sum == MIN && root->data < leaf)) MIN = sum, leaf = root->data;
    } else {
        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);
    }
}

int main() {
    while (read()) {
        root = build(a[0], a[1], n);
        MIN = leaf = INF;
        dfs(root, 0);
        printf("%d\n", leaf);
    }
    return 0;
}
