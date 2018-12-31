//ÌâÄ¿Á´½Ó£ºhttps://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define M 15
#define N 110000

char d;
int n;
char s1[N], s2[N];

void insert(char s2[], int &k, int sum) {
    int i = 0;
    char s[100];
    while (sum) {
        s[i++] = sum % 10 + '0';
        sum = sum / 10;
    }
    s[i] = '\0';
    reverse(s, s + i);
    for (int j = 0; j < i; ++j) {
        s2[k++] = s[j];
    }
    s2[k] = '\0';
}

int main() {
    int i = 1;
    scanf("%c %d", &d, &n);
    s2[0] = d; s2[1] = '\0';
    while (i++ < n) {
        memcpy(s1, s2, sizeof(s2));
        int sum = 1, k = 0;
        int len = strlen(s1);
        for (int j = 1; j < len; ++j) {
            if (s1[j] == s1[j - 1]) {
                ++sum;
            } else {
                s2[k++] = s1[j - 1]; insert(s2, k, sum);
                sum = 1;
            }
        }
        if (sum) {
            s2[k++] = s1[len - 1]; insert(s2, k, sum);
        }
    }
    puts(s2);
    return 0;
}
