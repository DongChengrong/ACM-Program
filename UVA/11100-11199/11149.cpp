/*
等比数列求和
当 n == 0时返回1
当 n为奇数时返回 (1 + a^(n / 2 + 1)) * S(n/2) + a ^ (n / 2 + 1)
当 n为偶数时返回 (1 + a ^ (n / 2)) * S(n/2)
*/
#include<stdio.h>
#include<string.h>

#define N 100

typedef long long LL;

LL n,k;

struct Mat
{
    LL a[N][N];
    Mat()
    {
        memset(a,0,sizeof(a));
    }

    Mat operator * (const Mat & b)
    {
        Mat c;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    c.a[i][j] = (c.a[i][j] + a[i][k]* b.a[k][j]) % 10;
        return c;
    }

    Mat operator + (const Mat & b)
    {
        Mat c;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                c.a[i][j] = (a[i][j] + b.a[i][j]) % 10;
        return c;
    }
};

Mat I;

Mat pow_mul(Mat a, LL k)
{
    Mat b = a;
    k--;
    while(k)
    {
        if(k & 1) a = a * b;
        b = b * b;
        k = k >> 1;
    }
    return a;
}

void print(Mat a)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            printf("%lld%c",a.a[i][j] % 10,j == n - 1 ? '\n' : ' ');
    putchar('\n');
}

Mat sum(Mat a, LL k)
{
    Mat ans;
    if(k == 1) return a;
    else ans = sum(a, k / 2);

    if(k & 1)
    {
        Mat t = pow_mul(a, k / 2 + 1);
        ans = ans * (t + I) + t;
    }
    else
    {
        Mat t = pow_mul(a, k / 2);
        ans = ans * (t + I);
    }
    return ans;
}

int main()
{
    while(scanf("%lld%lld",&n,&k) == 2 && n)
    {
        Mat res,a;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(i == j) I.a[i][j] = 1;
                scanf("%lld",&a.a[i][j]);
                a.a[i][j] %= 10;
            }

        res = sum(a,k);

        print(res);

    }
    return 0;
}
