void meger(int a[], int l, int mid, int r) {
    int b[11000];
    int i = l, j = mid + 1;
    int n = 0;
    while (i <= mid || j <= r) {
        if (i > mid) { b[n++] = a[j++]; continue; }
        if (j > r) { b[n++] = a[i++]; continue; }
        if (a[i] > a[j]) b[n++] = a[j++];
        else b[n++] = a[i++];
    }
    for (i = 0; i < n; ++i) a[l + i] = b[i];
}

void meger_sort(int a[], int l, int r) {
    if (l >= r) return;
    int mid = (r + l) / 2;
    meger_sort(a, l, mid);
    meger_sort(a, mid + 1, r);
    meger(a, l, mid, r);
}
