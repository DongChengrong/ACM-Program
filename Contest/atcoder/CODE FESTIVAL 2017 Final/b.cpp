#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 10;
char s[maxn];

int a[10];

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	while(scanf("%s",s) == 1)
	{
		memset(a,0,sizeof(a));
		for(int i = 0; i < strlen(s); i++)
			a[s[i] - 'a']++;

		int ok = 1;
		sort(a,a+3,cmp);
		if(a[0] - a[1] > 1) ok = 0;
		if(a[0] - a[2] > 1) ok = 0;
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
