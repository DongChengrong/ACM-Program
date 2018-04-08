#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn=200;
char s[maxn];

int main(){
    int T;
    scanf("%d",&T); getchar();
    while(T--){
        gets(s);
        stack<char> S;
        for(int i=0;i<strlen(s);i++){
            if(s[i]==')'){
                if(S.empty()) { S.push(s[i]); break; }
                char c=S.top();
                if(c!='(') break;
                S.pop();
            }else if(s[i]==']'){
                if(S.empty()) { S.push(s[i]); break;}
                char c=S.top();
                if(c!='[') break;
                S.pop();
            }else {
                S.push(s[i]);
            }
        }
        if(S.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
