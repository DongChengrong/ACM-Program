#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int maxn=50+10;
int a[maxn],b[maxn];

int main(){
    srand((unsigned)time(NULL));
    for(int i=1;i<=30;i++){
        a[i]=(rand()%(300-200+1)+200);
    }
    int j=0;
    for(int i=1;i<=30;i++){
        if(a[i]%2==0) b[++j]=a[i];
    }
    for(int i=1;i<j;i++){
        for(int k=i+1;k<=j;k++){
            if(b[k]>b[i]){
                int temp=b[i];
                b[i]=b[k];
                b[k]=temp;
            }
        }
    }
    for(int i=1;i<=j;i++) printf("%d ",b[i]);
    printf("\n");
    return 0;
}
