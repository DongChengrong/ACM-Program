#import<cstdio>

int main()
{
    int K,i=scanf("%d",&K)-2,n=K+3>>2<<1,j,k;
    for(printf("%d",n); ++i<n;)for(j=puts("")-2; ++j<n; printf("%d ",((k=i%2*n+(i+j)%n)>=K?k-n:k)%K+1));
}
