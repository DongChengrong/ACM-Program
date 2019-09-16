#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <algorithm>

#define N 11000

using namespace std;

int c[] = {4, 8, 15, 16, 23, 42};

int a[N];
int b[N];

int main() {
    //for (int i = 0; i < 6; ++i) for (int j = i + 1; j < 6; ++j) printf("%d\n", c[i] * c[j]);
    unordered_map<int, int> ma;
    int x, pre, suf;
    puts("? 1 2"); fflush(stdout); scanf("%d", &x); fflush(stdout);
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (c[i] * c[j] == x) {
                pre = c[i]; suf = c[j];
                ma[pre] = 1; ma[suf] = 1;
            }
        }
    }

    puts("? 2 3"); fflush(stdout); scanf("%d", &x); fflush(stdout);
    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (c[i] * c[j] == x) {
                ma[c[i] ]++; ma[c[j] ]++;
                if (ma[pre] == 2) {
                    a[1] = pre;
                    a[0] = suf;
                    if (c[i] == pre) pre = c[j];
                    else pre = c[i];
                } else if (ma[suf] == 2) {
                    a[1] = suf;
                    a[0] = pre;
                    if (c[i] == suf) pre = c[j];
                    else pre = c[i];
                }
                goto LOOP;
            }
        }
    }
    LOOP:;
    a[2] = pre; ma[pre] = 1;

    puts("? 3 4"); fflush(stdout); scanf("%d", &x); fflush(stdout);
    for (int i = 0; i < 6; ++i) {
        if (c[i] == pre || ma[c[i] ]) continue;
        if (pre * c[i] == x) {
            pre = c[i]; a[3] = pre;
            ma[pre] = 1; break;
        }
    }

    puts("? 4 5"); fflush(stdout); scanf("%d", &x); fflush(stdout);
    for (int i = 0; i < 6; ++i) {
        if (c[i] == pre || ma[c[i] ]) continue;
        if (pre * c[i] == x) {
            pre = c[i]; a[4] = pre;
            ma[pre] = 1; break;
        }
    }

    for (int i = 0; i < 6; ++i) if (!ma[c[i]]) a[5] = c[i];

    fflush(stdout);
    printf("!");
    for (int i = 0; i < 6; ++i) printf(" %d", a[i]); puts(""); fflush(stdout);
    return 0;
}

/*
32
120
240
368
*/