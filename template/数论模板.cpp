#include<stdio.h>
#include<math.h>
#include<string.h>

typedef long long LL;

const int maxn = 10000000 + 10;
const int maxp = 700000;

int vis[maxn];
int prime[maxp];

//���Բ��ԣ������жϵ��������Ƿ�������
int is_prime(LL n)
{
    if(n <= 1) return 0;
    LL m = floor(sqrt(n) + 0.5);
    for(LL i = 2; i <= m; i++)
        if(n % i == 0) return 0;
    return 1;
}

//ɸѡ����
void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2; i <= m; i++)
        for(int j = i * i; j <= n; j += i)
            vis[j] = 1;
}

//��������������prime�����У�������������
int gen_primes(int n)
{
    sieve(n);
    int c = 0;
    for(int i = 2; i <= n; i++)
        prime[c++] = i;
    return c;
}

//ŷ������㷨������շת�������
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

//��չŷ������㷨
void gcdEx(LL a, LL b, LL &d, LL &x, LL &y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else { gcdEx(b, a % b, d, y, x); y -= x * (a / b); }
}

//ģ����
LL mul_mod(LL a, LL b, LL n)
{
    return a * b % n;
}

//������+ģ����
LL pow_mod(LL a, LL p, LL n)
{
    if(p == 0) return 1;
    if(p == 1) return a % n;

    LL ans = pow_mod(a, p / 2, n);
    ans = ans * ans % n;
    if(p & 1) ans = ans * a % n;
    return ans;
}

//���㵥��ŷ������
int euler_phi(int n)
{
    int m = (int)sqrt(n + 0.5);
    int ans = n;
    for(int i = 2; i <= m; i++)
        if(n % i == 0){
            ans = ans / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    if(n > 1) ans = ans / n * (n - 1);
    return ans;
}

//ŷ��������
int phi[maxn];
void phi_table(int n)
{
    for(int i = 2; i <= n; i++) phi[i] = 0;
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = i; j <= n; j += i){
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
}

//����ģn��a����
LL inv(LL a, LL n)
{
    LL d, x, y;
    gcdEx(a,n,d,x,y);
    return d == 1 ? (x + n) % n : -1;
}
