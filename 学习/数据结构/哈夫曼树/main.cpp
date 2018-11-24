#include <stdio.h>
#include "huffman.h"

int a[MAXN];

int main() {
    int n, i;
    puts("请输入数组的长度并输入该数组：");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    build_and_coding(a, n);
    puts("哈夫曼树"); print_huffman_tree(n);
    puts("哈夫曼编码"); print_all_codes(n);
    return 0;
}

//sample input
/*
8
5 29 7 8 14 23 3 11
*/
//sample output
/*
0001
10
1110
1111
110
01
0000
001
*/
