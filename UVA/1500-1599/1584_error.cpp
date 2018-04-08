#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=100+10;
char s[maxn];
int A[maxn],B[maxn],C[maxn],D[maxn],temp[maxn];
int An,Bn,Cn,Dn,n;

int less(char c)
{
    switch(c)
    {
        case 'A' :
        {
            int i=1;
            while(A[n]!=1)
            {
                char c=s[A[0]];
                for(int j=1;j<An;j++) { int k=(A[j]+i)/n; if(s[k]<c) c=s[k]; }
                int l=0;
                for(int j=0;j<An;j++)
                {
                    int k=(A[j]+i)/n;
                    if(s[k]<c) temp[l++]=A[j];
                }
                for(int j=0;j<l;j++) A[j]=temp[j];
                i++;
                An=l;
            }
        }
        case 'B' :
        {
            int i=1;
            while(B[n]!=1)
            {
                char c=s[B[0]];
                for(int j=1;j<Bn;j++) { int k=(B[j]+i)/n; if(s[k]<c) c=s[k]; }
                int l=0;
                for(int j=0;j<Bn;j++)
                {
                    int k=(B[j]+i)/n;
                    if(s[k]<c) temp[l++]=B[j];
                }
                for(int j=0;j<l;j++) B[j]=temp[j];
                i++;
                Bn=l;
            }
        }
        case 'C' :
        {
            int i=1;
            while(C[n]!=1)
            {
                char c=s[C[0]];
                for(int j=1;j<Cn;j++) { int k=(C[j]+i)/n; if(s[k]<c) c=s[k]; }
                int l=0;
                for(int j=0;j<Cn;j++)
                {
                    int k=(C[j]+i)/n;
                    if(s[k]<c) temp[l++]=C[j];
                }
                for(int j=0;j<l;j++) C[j]=temp[j];
                i++;
                Cn=l;
            }
        }
        case 'D' :
        {
            int i=1;
            while(D[n]!=1)
            {
                char c=s[D[0]];
                for(int j=1;j<Dn;j++) { int k=(D[j]+i)/n; if(s[k]<c) c=s[k]; }
                int l=0;
                for(int j=0;j<Dn;j++)
                {
                    int k=(D[j]+i)/n;
                    if(s[k]<c) temp[l++]=D[j];
                }
                for(int j=0;j<l;j++) D[j]=temp[j];
                i++;
                Dn=l;
            }
        }
    }
    return temp[0];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        An=Bn=Cn=Dn=0;
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++)
        {
            switch(s[i])
            {
                case 'A': A[An++]=i; break;
                case 'B': B[Bn++]=i; break;
                case 'C': C[Cn++]=i; break;
                case 'D': D[Dn++]=i; break;
            }
        }
        if(An==n || Bn==n || Cn==n || Dn==n) printf("%s\n",s);
        else
        {
            if(An!=0){ int k=less('A'); printf("%s",s+k); s[k]='\0'; printf("%s\n",s); continue; }
            if(Bn!=0){ int k=less('B'); printf("%s",s+k); s[k]='\0'; printf("%s\n",s); continue; }
            if(Cn!=0){ int k=less('C'); printf("%s",s+k); s[k]='\0'; printf("%s\n",s); continue; }
            if(Dn!=0){ int k=less('D'); printf("%s",s+k); s[k]='\0'; printf("%s\n",s); continue; }
        }
    }
    return 0;
}
