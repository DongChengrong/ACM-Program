#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
    int sum = 0;
    char p = 'a',c;
    while((c = getchar()))
    {
        if(c == EOF) break;
        if(c == '\n'){
            printf("%d\n",sum);
            sum = 0;
            p = 'a';
            continue;
        }
        if(p < c) sum += min(abs(p - c), abs(p - c + 26));
        if(p > c) sum += min(abs(p - c), abs(p - c - 26));
        p = c;
    }
    return 0;
    return 0;
}
