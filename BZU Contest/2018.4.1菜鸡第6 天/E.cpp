/*
实际上就是构建一个链表
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

#define N 301000

int vis[N],pre[N],tail[N];

int main(){
    int n,q;
    while(scanf("%d%d",&n,&q) == 2){

        memset(vis,0,sizeof(vis));
        memset(pre,-1,sizeof(pre));
        memset(tail,-1,sizeof(tail));

        int id =  1,last = 0,sum = 0;
        while(q--){
            int op,x;
            scanf("%d%d",&op,&x);
            if(op == 1){
                pre[id] = tail[x];
                tail[x] = id++;
                sum++;
            }
            if(op == 2){
                int tmp = tail[x];
                while(tmp != -1 && !vis[tmp]){    //id为-1代表到了链表的头
                    vis[tmp] = 1;
                    sum--;
                    tmp = pre[tmp];
                }
            }
            if(op == 3){
                for(int i = last +1; i <= x; i++){
                    if(!vis[i]){
                        vis[i] = 1; sum--;
                    }
                }
                last = max(last,x);
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
