#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

const int maxm=50+10;
const int maxn=1000+10;
const char dna[]="TAGC";

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n,ham=0;
        map<char,int> mm[maxn];
        string DNA[maxm];
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++) cin>>DNA[i];
        for(int i=0;i<n;i++)   //init
            for(int j=0;j<4;j++)
                mm[i][dna[j]]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                char c=DNA[j][i];
                mm[i][c]++;
            }
        for(int i=0;i<n;i++)
        {
            int pos=0,ans=0;
            for(int j=0;j<4;j++)
            {
                char c=dna[j];
                int temp=mm[i][c];
                if(temp>ans) { ans=temp; pos=j; }
                else{ if(temp==ans){
                    if(dna[j]<dna[pos]) pos=j;
                    ans=temp; }
                }
            }
            ham+=(m-ans);
            printf("%c",dna[pos]);
        }
        printf("\n%d\n",ham);
    }
}
