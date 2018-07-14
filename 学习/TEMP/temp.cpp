#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d %d\n", !(x > 0 || y > 0), !(x > 0 && !(y > 0) ) );
    return 0;
}
