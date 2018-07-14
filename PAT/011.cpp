/*
*ÌâÄ¿Á´½Ó£ºhttps://www.nowcoder.com/pat/6/problem/4040
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 1100

char s1[N], s2[N];
char weeks[][10] = {"MON","TUE","WED","THU", "FRI", "SAT", "SUN" };

int main() {
    while (scanf("%s%s", s1, s2) == 2) {
        int a, b, c;
        int flag = 0;
        for (int i = 0; i < strlen(s1); ++i) {
            if (s1[i] == s2[i]) {
                if (flag) {
                    if (isdigit(s1[i])) {
                        b = s1[i] - '0';
                    } else {
                        b = tolower(s1[i]) - 'a' + 10;
                    }
                    break;
                } else {
                    if (!isupper(s1[i])) continue;
                    a = tolower(s1[i]) - 'a';
                    flag = 1;
                }
            }
        }
        scanf("%s%s", s1, s2);
        for (int i = 0; i < strlen(s1); ++i) {
            if (s1[i] == s2[i] && isalpha(s1[i])) {
                c = i; break;
            }
        }
        printf("%s %s%d:%s%d\n", weeks[a], b < 10 ? "0" : "", b, c < 10 ? "0" : "", c);
    }
    return 0;
}
