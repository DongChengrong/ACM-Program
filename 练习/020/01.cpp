#include<stdio.h>
#include<math.h>

double f(double a,double b)
{
    return a*a*a+b*b+sin(a);
}

int main(){
    double a,b;
    printf("please input a and b:\n");
    scanf("%lf%lf",&a,&b);
    printf("%.3lf",f(a,b));
}
