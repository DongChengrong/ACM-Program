#include<stdio.h>
#include<math.h>

int main()
{
    double n,p;
    while(scanf("%lf%lf",&n,&p) == 2)
        printf("%0.0lf\n",exp(log(p) / n));
    return 0;
}
