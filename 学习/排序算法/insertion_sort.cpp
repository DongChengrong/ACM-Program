#define _for(i, a, b) for (int i = (a); i < (b); ++i)

void insertion_sort(int a[], int n) {
    _for (i, 0, n) {
        int j;
        for (j = 0; j < i; ++j) {
            if (a[j] > a[i]) break;
        }
        if (j < i) {
            int tmp = a[i];
            for (int k = i; k > j; --k) a[k] = a[k - 1];
            a[j] = tmp;
        }
    }
}
