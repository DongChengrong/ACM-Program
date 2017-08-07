#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

struct node
{
    int id;
    char s[50];
}S[100];

int cmp(struct node s1,struct node s2)
{
    return s1.id<s2.id;
}

void mark()
{
    int a,t,c,g;
    for(int i=0;i<m;i++){  a=c=t=g=0;
        for(int j=n-1;j>=0;j--)
        {
            switch(S[i].s[j])
            {
                case 'A' :
                    {
                        a++;
                        break;
                    }
                case 'C' :
                    {
                        c++;
                        S[i].id+=a;
                        break;
                    }
                case 'G':
                    {
                        g++;
                        S[i].id+=a;
                        S[i].id+=c;
                        break;
                    }
                case 'T':
                    {
                        t++;
                        S[i].id+=a;
                        S[i].id+=c;
                        S[i].id+=g;
                        break;
                    }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    { cin>>S[i].s; S[i].id=0;}
    mark();
    sort(S,S+m,cmp);
    for(int i=0;i<m;i++)
        cout<<S[i].s<<endl;
    return 0;
}
