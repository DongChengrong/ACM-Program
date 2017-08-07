#include<stdio.h>

double compute(double i){
    double j=i*2;
    return ((2*i+1)*(2*i-1))/(j*j);
}

int main(){
    int n;
    double sum=0;
    printf("please input a integer:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=compute(i);
    }
    printf("%lf\n",sum);
}
