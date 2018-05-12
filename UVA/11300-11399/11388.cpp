/*
在这个题中，若使满足题目的整数对（a,b）存在，则必有l % g == 0
而当存在满足题意的解时，要想让a最小，则a = g
此时a * b / g = l 即 g * b / g = l
亦即b = l
*/

#include <stdio.h>

int main() {
    int T, l, g;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&g,&l);
        if (l % g != 0) {
            printf("-1\n");
        } else {
            printf("%d %d\n",g,l);
        }
    }
    return 0;
}
