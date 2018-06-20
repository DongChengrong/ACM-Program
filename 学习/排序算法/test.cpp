#include <stdio.h>
#include "insertion_sort.cpp"
#include "simple_chose_sort.cpp"
#include "meger_sort.cpp"
#include "bubble_sort.cpp"

#define N 1100
#define _for(i, a, b) for (int i = (a); i < (b); ++i)

const int n = 11;

int a[N] = {1, 4, 9, 3, 2, 5, 1, 3, 7, 8, 7};

int main() {
    //insertion_sort(a, n);
    //simple_chose_sort(a, n);
    //meger_sort(a, 0, n - 1);
    bubble_sort(a, n);
    _for (i, 0, n) printf("%d ",a[i]); puts("");
    return 0;
}
