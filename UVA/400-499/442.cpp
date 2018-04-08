#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn=1000+10;
char s[maxn];

struct Node{
    int row,col;
    Node(int row=0,int col=0):row(row),col(col){}
}M[26];

int main(){
    int N;
    scanf("%d",&N); getchar();
    while(N--){
        char c;
        scanf("%c",&c);
        scanf("%d %d",&M[c-'A'].row,&M[c-'A'].col); getchar();
    }
    while(scanf("%s",s)==1){
        stack<Node> S;
        int error=0;
        long long sum=0;
        for(int i=0;i<strlen(s);i++){
            if(isalpha(s[i])) S.push(M[s[i]-'A']);
            else if(s[i]==')'){
                Node p2=S.top(); S.pop();
                Node p1=S.top(); S.pop();
                if(p1.col!=p2.row) { error=1; break; }
                sum+=p1.row*p1.col*p2.col;
                S.push(Node(p1.row,p2.col));
            }
        }
        if(error) printf("error\n");
        else printf("%lld\n",sum);
    }
    return 0;
}
