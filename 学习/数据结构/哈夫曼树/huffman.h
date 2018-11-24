#include <stdlib.h>

#define MAXN 5500   //�����������ռ�õĿռ�

typedef struct Node {
    int right, left, fa, weight;
}Node;

Node Huffman[MAXN];   //��������

typedef char *str;  //�Զ����ַ�������
str codes[MAXN];   //����������

/*
*���ڽ��������������Ƚϸ��ӣ������ҷֳ�������д
*��һ������ɽ�������װ��һ������(build)��ȥ
*�ڶ�������ɱ��룬��װ��һ������(coding)��ȥ
*�������дһ�������ֱ����build��coding����
*/

void select(int n, int &a, int &b) {
    int i;
    a = b = -1;  //��ʼ��һ��������ȡ����ֵ
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

//��һ���֣�����
void build(int a[], int n) {
     //��̵�һ������ʼ��
    int i, j;
    //Ϊ������⣬�±��1��ʼ
    for (i = 1; i <= n; ++i) Huffman[i] = (Node){0, 0, -1, a[i - 1]};

    //������û�и��ף����ڵ㣩�Ľڵ���ѡ������Ȩֵ��С��
    for (i = n + 1; i <= 2 * n - 1; ++i) {
        int u, v;
        select(i - 1, u, v);
        Huffman[u].fa = Huffman[v].fa = i;
        Huffman[i].fa = -1;
        Huffman[i].weight = Huffman[u].weight + Huffman[v].weight;
        Huffman[i].left = u; Huffman[i].right = v;
    }
}

//�ڶ����֣�����
void coding(int n) {
    int i, fa;
    str tmp = (str)malloc(sizeof(char) * n);
    for (i = 1; i <= n; ++i) {
        int j = 0, k = 0;
        int fa = Huffman[i].fa;
        int child = i;
        while (fa != -1) {
            tmp[j++] = (Huffman[fa].left == child ? '0' : '1');  //ʹ����Ŀ������򻯴���
            child = fa, fa = Huffman[fa].fa;
        }
        tmp[j] = '\0';
        codes[i] = (str)malloc(sizeof(char) * n);
        while (j > 0) codes[i][k++] = tmp[--j];
        codes[i][k] = '\0';
    }
}

//������������������
void build_and_coding(int a[], int n) {
    build(a, n);   //���ú�������
    coding(n);    //���ú�������
}

//��ӡ��������
void print_huffman_tree(int n) {
    for (int i = 1; i <= 2 * n - 1; ++i)
        printf("%d %d %d %d %d\n", i, Huffman[i].weight, Huffman[i].fa, Huffman[i].left, \
            Huffman[i].right);
}

//������еĹ���������
void print_all_codes(int n) {
    int i;
    for (i = 1; i <= n; ++i) puts(codes[i]);
}
