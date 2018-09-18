#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

char a[5];

int main()
{
    while(scanf("%s",a) == 1)
    {
        int c = 0;
        for(int i = 0; i < 3; i++)
            if(a[i] - '0') c++;
        printf("%d\n",c);
    }
    return 0;
}
