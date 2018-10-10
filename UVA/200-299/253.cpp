//#include <stdio.h>
//#include <string.h>
//
//int left[] = {4, 0, 2, 3, 5, 1};
//int up[] = {2, 1, 5, 0, 4, 3};
//
//void rot(int T[], int p[]) {
//    for (int i = 0; i < 6; ++i) p[i] = T[p[i]];
//}
//
//int main() {
//
//    int p0[10] = {0, 1, 2, 3, 4, 5};
//    freopen("out.txt", "w", stdout);
//    printf("int dice[24][6] = {");
//    for (int i = 0; i < 6; ++i) {
//        int p[10];
//        memcpy(p, p0, sizeof(p));
//        if (i == 0) {
//            rot(up, p);
//        } else if (i == 1) {
//            rot(left, p); rot(up, p);
//        } else if (i == 3) {
//            rot(up, p); rot(up, p);
//        } else if (i == 4) {
//            rot(left, p); rot(left, p); rot(left, p); rot(up, p);
//        } else if (i == 5) {
//            rot(left, p); rot(left, p); rot(up, p);
//        }
//        for (int j = 0; j < 4; ++j) {
//            if (i || j) printf(",");
//            printf("{");
//            for (int k = 0; k < 6; ++k) printf("%d%c", p[k], k == 5 ? ' ' : ',');
//            printf("}");
//            rot(left, p);
//        }
//    }
//    printf("};");
//    return 0;
//}
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dice[24][6] = {{2,1,5,0,4,3 },{2,0,1,4,5,3 },{2,4,0,5,1,3 },{2,5,4,1,0,3 },{4,2,5,0,3,1 },{5,2,1,4,3,0 },{1,2,0,5,3,4 },{0,2,4,1,3,5 },{0,1,2,3,4,5 },{4,0,2,3,5,1 },{5,4,2,3,1,0 },{1,5,2,3,0,4 },{5,1,3,2,4,0 },{1,0,3,2,5,4 },{0,4,3,2,1,5 },{4,5,3,2,0,1 },{1,3,5,0,2,4 },{0,3,1,4,2,5 },{4,3,0,5,2,1 },{5,3,4,1,2,0 },{3,4,5,0,1,2 },{3,5,1,4,0,2 },{3,1,0,5,4,2 },{3,0,4,1,5,2 }};
char s[100];

int main() {
    while (scanf("%s", s) != EOF) {
        int flag = 0;
        for (int i = 0; i < 24; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (s[j] != s[dice[i][j] + 6]) { flag = flag + 1; break; }
            }
        }
        if (flag == 24) puts("FALSE");
        else puts("TRUE");
    }
    return 0;
}
