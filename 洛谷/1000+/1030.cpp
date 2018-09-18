//���ö���������������
#include <stdio.h>
#include <string.h>

#define N 110

void dfs(char s1[], char s2[], int sz) {   //sz��ʾ������ģ
    if (!sz) return;
    int i;
    printf("%c", s2[sz - 1]);
    for (i = 0; i < sz; ++i) {
        if (s1[i] == s2[sz - 1]) break;
    }
    dfs(s1, s2, i);  //left
    dfs(s1 + i + 1, s2 + i, sz - i - 1);  //right
}

int main() {
    char s1[N], s2[N];
    while (scanf("%s", s1) != EOF) {
        scanf("%s", s2);
        dfs(s1, s2, strlen(s1));
    }
    return 0;
}
