#include "stdio.h"
double fun(int a[],int m)
{int i;
double sum=0;
    for(i=0;i<m;i++)sum+=a[i];
  return(sum/m);
}
int main()
{int x,  count = 0,a[300];
for (x = 1;x <= 20;x++)
	if (x%2==0) {
	a[count]=x;
	count++;
	}
printf("\n这些偶数的平均值是:%6.0lf\n", fun(a,count));
return 0;
}
