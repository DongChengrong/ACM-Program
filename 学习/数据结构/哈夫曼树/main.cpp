#include <stdio.h>
#include "huffman.h"

int a[MAXN];

int main() {
    int n, i;
    puts("����������ĳ��Ȳ���������飺");
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &a[i]);
    build_and_coding(a, n);
    puts("��������"); print_huffman_tree(n);
    puts("����������"); print_all_codes(n);
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
