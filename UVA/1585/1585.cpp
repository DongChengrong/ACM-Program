#include<stdio.h>
#include<string.h>
const int maxn=100;

int main()
{
	char c[maxn];
	int n,ans,sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        sum=ans=0;
        for(int j=0;j<strlen(c);j++)
        {
            if(c[j]=='O') ans++;
            else if(c[j]=='X') ans=0;
            sum+=ans;
        }
        printf("%d\n",sum);
    }
	return 0;
}
