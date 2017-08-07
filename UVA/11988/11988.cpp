#include<cstdio>
#include<cstring>
using namespace std;

const int maxn= 100000+10;
char s[maxn];
int last,cur,next[maxn];

int main(){
    while(scanf("%s",s+1)==1){
        cur=last=0;
        next[0]=0;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            if(s[i]=='[') cur=0;
            else if(s[i]==']') cur=last;
            else{
                next[i]=next[cur];
                next[cur]=i;
                if(cur==last) last=i;
                cur=i;
            }
        }
        for(int i=0;next[i]!=0;i=next[i]) printf("%c",s[next[i]]);
        printf("\n");
    }
    return 0;
}
