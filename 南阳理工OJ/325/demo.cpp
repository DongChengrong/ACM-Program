#include <stdio.h>
#include <math.h>
int a[21],sum,all,n,i,j,min;
void dfs(int star)
{
    if(star==n)
        return ;
    if(fabs(all-sum*2)<min)//��ֵ��С����������ﲻ�� ������ ԭʽת���õ���
        min=fabs(all-sum*2);
    for(int j=star;j<n;j++)
    {
        sum+=a[j];
        dfs(j+1);
        sum-=a[j];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        all=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]),all+=a[i];
        min=n*10001;
        dfs(0);
        printf("%d\n",min);
    }
}
