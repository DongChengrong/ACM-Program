#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 10 + 5;
int a[maxn],b[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0; i < 6; i++)
            scanf("%d",&a[i]);
        for(int i = 0; i < 6; i++)
            scanf("%d",&b[i]);

        sort(a,a+6);
        sort(b,b+6);

        int a_num = 0,b_num = 0;

        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
            {
                if(a[i] > b[j])
                    a_num++;
                else if(a[i] < b[j])
                    b_num++;
            }

        if(a_num == b_num)
            printf("Tie\n");
        else if(a_num > b_num)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
