#include<cstdio>
#include<cstring>
int main()
{
    int i,n,k;
    int a[15];
    memset(a,0,sizeof(a));
    while(~scanf("%d",&k) && k!=0)
    {
        if(a[k]) {  printf("%d\n",a[k]); continue; }
        for(i=k+1;;i++)
        {
            n=2*k;
            int z=0;
            while(n>k)
            {
                int j=(i-z)%n;
                if(j>k) { z=n-j; n--;}
                else if(!j) { z=0; n--;}
                else break;
            }
            if(n<=k) break;
        }
        a[k]=i;
        printf("%d\n",i);
    }
    return 0;
}
