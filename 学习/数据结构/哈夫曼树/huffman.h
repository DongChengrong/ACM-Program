#include <stdlib.h>

#define MAXN 5500   //哈夫曼树最大占用的空间

typedef struct Node {
    int right, left, fa, weight;
}Node;

Node Huffman[MAXN];   //哈夫曼树

typedef char *str;  //自定义字符串类型
str codes[MAXN];   //哈夫曼编码

/*
*由于建树与编码合起来比较复杂，所以我分成两部分写
*第一部分完成建树，封装到一个函数(build)中去
*第二部分完成编码，封装到一个函数(coding)中去
*最后我们写一个函数分别调用build和coding函数
*/

void select(int n, int &a, int &b) {
    int i;
    a = b = -1;  //初始化一个不可能取到的值
    for (i = 1; i <= n; ++i) {
        if (Huffman[i].fa != -1) continue;
        if (a == -1 || (Huffman[i].weight < Huffman[a].weight)) a = i;
    }
    for (i = 1; i <= n; ++i) {
        if (Huffman[i].fa != -1) continue;
        if (i != a && (b == -1 || (Huffman[i].weight < Huffman[b].weight)) ) b = i;
    }
    //printf("%d %d\n", a, b);
}

//第一部分：建树
void build(int a[], int n) {
     //编程第一步，初始化
    int i, j;
    //为便于理解，下标从1开始
    for (i = 1; i <= n; ++i) Huffman[i] = (Node){0, 0, -1, a[i - 1]};

    //在所有没有父亲（根节点）的节点中选出两个权值最小的
    for (i = n + 1; i <= 2 * n - 1; ++i) {
        int u, v;
        select(i - 1, u, v);
        Huffman[u].fa = Huffman[v].fa = i;
        Huffman[i].fa = -1;
        Huffman[i].weight = Huffman[u].weight + Huffman[v].weight;
        Huffman[i].left = u; Huffman[i].right = v;
    }
}

//第二部分：编码
void coding(int n) {
    int i, fa;
    str tmp = (str)malloc(sizeof(char) * n);
    for (i = 1; i <= n; ++i) {
        int j = 0, k = 0;
        int fa = Huffman[i].fa;
        int child = i;
        while (fa != -1) {
            tmp[j++] = (Huffman[fa].left == child ? '0' : '1');  //使用三目运算符简化代码
            child = fa, fa = Huffman[fa].fa;
        }
        tmp[j] = '\0';
        codes[i] = (str)malloc(sizeof(char) * n);
        while (j > 0) codes[i][k++] = tmp[--j];
        codes[i][k] = '\0';
    }
}

//建立哈夫曼树并编码
void build_and_coding(int a[], int n) {
    build(a, n);   //调用函数建树
    coding(n);    //调用函数编码
}

//打印哈夫曼树
void print_huffman_tree(int n) {
    for (int i = 1; i <= 2 * n - 1; ++i)
        printf("%d %d %d %d %d\n", i, Huffman[i].weight, Huffman[i].fa, Huffman[i].left, \
            Huffman[i].right);
}

//输出所有的哈夫曼编码
void print_all_codes(int n) {
    int i;
    for (i = 1; i <= n; ++i) puts(codes[i]);
}
