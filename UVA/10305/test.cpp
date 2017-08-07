#include<cstdio>
#include<cstring>
using namespace std;

int main()
{

    int a[20];
    int i=9;
    memset(a,0,sizeof(a));
    a[i--]=11;
    printf("%d %d\n",a[9],i);
    return 0;
}
