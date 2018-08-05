#include<stdio.h>
#include<string.h>

#define N 110

char s[N];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
    {
        int i = 0, cnt = 0, sum = 0;
        scanf("%s", s);
        while (i < strlen(s)) {
            if (s[i] == 'O') cnt++;
            else cnt = 0;
            sum += cnt;
            i++;
        }
        printf("%d\n",sum);
    }
	return 0;
}
