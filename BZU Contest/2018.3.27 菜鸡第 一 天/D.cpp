/*
就目前来看该题为模拟题
加减操作都好实现，但是难得是?操作
涉及map集合的遍历以及匹配
*/

#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

#define N 20

typedef long long LL;

map<LL,LL> m;
char s[N];

int main(){
    int n;
    while(scanf("%d",&n) == 1)
    {
        LL x;
        char c;
        m.clear();
        while(n--){
            getchar();
            scanf("%c",&c);
            if(c == '?'){
                LL sum = 0;
                scanf("%s",s);
                for(map<LL,LL> ::iterator it = m.begin(); it != m.end(); it++){
                    x = it->first;
                    bool ok = true;
                    for(int i = strlen(s) - 1; i >= 0; i--){
                        int t = x % 10; x /= 10;
                        if(s[i] == '0' && t % 2 == 1) { ok = false; break; }
                        if(s[i] == '1' && t % 2 == 0) { ok = false; break; }
                    }
                    if(ok) sum += it->second;
                }
                printf("%lld\n",sum);
            }else{
                scanf("%lld",&x);
                if(c == '+') m[x]++;
                else m[x]--;
            }
        }
    }
    return 0;
}
