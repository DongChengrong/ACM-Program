#include <stdio.h>
#include <string.h>

#define N 50

int n, len;
int bits[N];
int buffer[N];

int a[5], b[5];

void bit_generator() {
    int i = 31, j, k;
    for (j = 3; j >= 0; --j) {
        for (k = 0; k < 8; ++k) {
            buffer[i--] = (a[j] & 1);
            a[j] = a[j] >> 1;
        }
    }
}

void add(int flag) {
    int i, k;
    bit_generator();
    if (!flag) memcpy(bits, buffer, sizeof(bits));
    else {
        for (i = 0; i < len; ++i) {
            if (buffer[i] == bits[i]) continue;
            else {
                for (k = i; k < len; ++k) bits[k] = 0;
                len = i;
                break;
            }
        }
    }

}

void to_digit() {
    int i, j;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(buffer, 0, sizeof(buffer));
    for (i = 0; i < len; ++i) buffer[i] = 1;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 8; ++j) {
            a[i] = (a[i] << 1) + bits[i * 8 + j];
            b[i] = (b[i] << 1) + buffer[i * 8 + j];
            if (len) len = len - 1;
        }
    }

}

int main() {
    while (scanf("%d", &n) != EOF) {
        int i; len = 32;
        scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
        add(0);
        for (i = 0; i < n - 1; ++i) {
            scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
            add(1);
        }
        to_digit();
        printf("%d.%d.%d.%d\n", a[0], a[1], a[2], a[3]);
        printf("%d.%d.%d.%d\n", b[0], b[1], b[2], b[3]);
    }
    return 0;
}
