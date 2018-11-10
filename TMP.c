#include <stdio.h>

int main() {
    char c;
    while (scanf("%c", &c) && c != '\n') {
        printf("  %c\n", c);
        printf(" %c%c%c\n",  c, c, c);
        printf("%c%c%c%c%c", c, c, c, c, c);
    }
    return 0;
}
