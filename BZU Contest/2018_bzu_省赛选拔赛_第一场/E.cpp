#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 1010
#define INF 0x3f3f3f3f

char s[N];

int main()
{
    int n;
    while(scanf("%s",s) == 1 && s[0] != 'E')
    {
        int z,o,j;
        z = o = j = 0;

        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == 'Z') z++;
            if(s[i] == 'O') o++;
            if(s[i] == 'J') j++;
        }

        while(z > 0 || o > 0 || j)
        {
            if(z){
                printf("Z"); z--;
            }
            if(o){
                printf("O"); o--;
            }
            if(j){
                printf("J"); j--;
            }
        }
        printf("\n");
    }
    return 0;
}