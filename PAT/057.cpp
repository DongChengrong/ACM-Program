//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/submissions
#include <stdio.h>
#include <map>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define N 11000

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node, *Tree;

int a[N];
int n, m;
map<int, int> ma;

Tree build(int a[], int n) {
    if (n <= 0) return NULL;
    int i;
    Tree root = (Tree)malloc(sizeof(Node));
    root->data = a[0];
    for (i = 1; i < n; ++i) if (a[i] > a[0]) break;
    root->left = build(a + 1, i - 1); root->right = build(a + i, n - i);
    return root;
}

void dfs(Tree root, int u, int v) {
    if (root == NULL) return;
    if (root->data == u) {
        printf("%d is an ancestor of %d.\n", u, v);
        return;
    } else if (root->data == v) {
        printf("%d is an ancestor of %d.\n", v, u);
        return;
    } else if ((root->data > u && root->data < v) || (root->data > v && root->data < u)) {
        printf("LCA of %d and %d is %d.\n", u, v, root->data);
        return;
    } else if (root->data > u) dfs(root->left, u, v);
    else dfs(root->right, u, v);
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ma[a[i]] = 1;
    }
    Tree root = build(a, n);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!ma[u] && !ma[v]) printf("ERROR: %d and %d are not found.\n", u, v);
        else if(!ma[u] || !ma[v]) printf("ERROR: %d is not found.\n", ma[u] ? v : u);
        else dfs(root, u, v);
    }
    return 0;
}
