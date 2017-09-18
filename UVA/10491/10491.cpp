#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    double a,b,c;
    while(cin >> a >> b >> c)
    {
        printf("%.5lf\n", (a * b + b * (b - 1)) / ((a+b) * (a + b - c - 1)));
    }
    return 0;
}
