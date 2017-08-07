#include<cstdio>
using namespace std;

int test,ok;
int sq1,sq2,sq3;
int a,b;
int x,y,z;

void init()
{
    test=0; ok=1;
    x=y=z=-1;
    sq1=sq2=sq3=0;
}

void judge()
{
    if(!ok) return;
    if(a!=x && a!=y && z==-1) z=a;
    else if(a!=x && a!=y && z!=-1 && a!=z) { ok=0; return; }
    if(b!=x && b!=y && z==-1) z=b;
    else if(b!=x && b!=y && z!=-1 && b!=z) { ok=0; return; }
    if(((a==x && b==y ) || (b==x && a==y)) && sq1!=2 ) sq1++;
    else if( ((a==y && b==z ) || (b==y && a==z)) && sq2!=2 ) sq2++;
    else if(((a==z && b==x) || (a==x && b==z)) && sq3!=2 ) sq3++;
    else ok=0;
}

void print()
{
    if(ok) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    init();
}

int main()
{
    init();
    while(scanf("%d %d",&a,&b)==2)
    {
        if(test==0) { x=a,y=b; sq1++; test++; continue; }
        judge();
        test++;
        if(test==6) print();
    }
    return 0;
}
