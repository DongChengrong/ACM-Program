/*
*因为把11月当成了31天而导致了10次WA
*
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int maxn = 1000;
int d[10];
char s[maxn];

int main()
{
    while(scanf("%d/%d/%d",&d[1],&d[2],&d[3]) == 3)
    {
        int flag = 0;  //表示是否是闰年

        if((d[1] % 4 == 0 && d[1] % 100 != 0) || d[1] % 400 == 0 ) flag = 1;

        int day = (d[2] - 1) * 31 + d[3];

        if(d[2] > 2 && flag) day -= 2;
        if(d[2] > 2 && !flag) day -= 3;
        if(d[2] > 4) day -= 1;
        if(d[2] > 6) day -= 1;
        if(d[2] > 9) day -= 1;
        if(d[2] > 11) day -= 1;

        printf("%d\n",day);
    }
    return 0;
}
