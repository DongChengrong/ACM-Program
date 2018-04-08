#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 100 + 10

int a[10];
char s[N];

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        for(int i = 0; i < n; i++){
            if(s[i] == 'U') a[0]++;
            if(s[i] == 'D') a[1]++;
            if(s[i] == 'L') a[2]++;
            if(s[i] == 'R') a[3]++;
        }
        printf("%d\n",min(a[0],a[1]) * 2 + min(a[2],a[3]) * 2);
    }
    return 0;
}
