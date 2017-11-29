#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int maxn = 100;
int d[maxn];

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int ans = 24;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&d[i]);
			ans = min(ans,d[i]);
		}
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				int m = -1;
				m = max(m,abs(d[i] - d[j]));
				m = max(m,abs(d[i] - (24 - d[j])));
				m = max(m,abs((24 - d[i]) - d[j]));
				m = max(m,abs((24 - d[i]) - (24 - d[j])));
				ans = min(ans,m);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
