#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

int slove(long long int num)
{
    int count = 0;
    for(int i = 1; i <= num; i++)
    {
        if(i > sqrt(num)) break;
        count++;
    }
    return count;
}

int main()
{
    long long int num;
    while(cin >> num)
    {
        printf("%d\n",slove(num));
    }
    return 0;
}
