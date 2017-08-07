#include<iostream>
using namespace std;
bool solve()
{
    bool b1=true,b2=true;
    int w1,w2,d1,d2;
    cin>>w1>>d1>>w2>>d2;
    if(w1==0)
        b1==solve();
    if(w2==0)
        b2=solve();
    return b1 && b2 &&(w1*d1==w2*d2);
}

int main()
{
    if(solve())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
