#include<cstdio>
#include<iostream>
using namespace std;

bool cmp(int &W)
{
    bool wegiht1,wegiht2;
    wegiht1=wegiht2=true;
    int wl,dl,wr,dr;
    cin>>wl>>dl>>wr>>dr;
    if(wl==0) wegiht1=cmp(wl);
    if(wr==0) wegiht2=cmp(wr);
    W=wl+wr;
    return (wegiht1 && wegiht2 && wl*dl==wr*dr);
}

int main()
{
    int Test,W;
    scanf("%d",&Test);
    while(Test--)
    {
        if(cmp(W)) printf("YES\n");
        else printf("NO\n");
        if(Test) cout<<endl;
    }
    return 0;
}
