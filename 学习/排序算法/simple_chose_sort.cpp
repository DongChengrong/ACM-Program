#define _for(i, a, b) for (int i = (a); i < (b); ++i)

void simple_chose_sort(int a[], int n) {
    _for (i, 0, n - 1) {
        _for (j, i + 1, n) {
            if (a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
