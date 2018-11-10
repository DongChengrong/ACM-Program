struct LIS
{
    int a[N], b[N];

    //��������������еĳ���
    int lis_1()
    {
        memset(b, INF, sizeof(b));
        for (int i = 0; i < n; ++i)
        {
            int p = lower_bound(b, b + n, a[i]) - b;
            b[p] = a[i];
        }
        return lower_bound(b, b + n + 10, INF) - b;
    }

    //��������½������еĳ���
    int lis_2()
    {
        memset(b, INF, sizeof(b));
        for (int i = 0; i < n; ++i)
        {
            int p = upper_bound(b, b + n + 10, a[i]) - b;
            b[p] = a[i];
        }
        return lower_bound(b, b + n + 10, INF) - b;
    }
};
