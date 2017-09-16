#include<iostream>
using namespace std;

long long f[1000010];

int main()
{
    long n;
    f[3] = 0;
    for(long long x = 4; x <= 1000000; x++)
        f[x] = f[x-1] + (((x - 1) * (x - 2)) / 2 - (x - 1) / 2) / 2;
    while(cin >> n)
    {
        if(n < 3) break;
        cout << f[n] <<endl;
    }
}
