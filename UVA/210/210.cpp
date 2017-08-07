#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=10000+10;
int var[26],locked;
int Q,t[6],N,id[maxn];
char progm[maxn][25];
deque<int> ready;
queue<int> stop;

void run(int pid){
    char *p=progm[id[pid]];
    int time=Q;
    while(time>0){
        switch(p[2]){
            case '=' :{
                int num=p[5]!='\0'?(p[4]-'0')*10+(p[5]-'0'):p[4]-'0';
                var[p[0]-'a']=num;
                time-=t[0];
                break;
            }
            case 'i':{
                printf("%d: %d\n",pid,var[p[6]-'a']);
                time-=t[1];
                break;
            }
            case 'c':{
                if(locked) { stop.push(pid); return; }
                else{
                    locked=1;
                    time-=t[2];
                    break;
                }
            }
            case 'l':{
                locked=0;
                if(!stop.empty()){
                    int n=stop.front(); stop.pop();
                    ready.push_front(n);
                }
                time-=t[3];
                break;
            }
            case'd': return;
        }
        id[pid]++;
        p=progm[id[pid]];
    }
    ready.push_back(pid);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        //input data
        scanf("%d",&N);
        for(int i=0;i<5;i++) scanf("%d",&t[i]);
        scanf("%d",&Q);
        getchar();

        memset(var,0,sizeof(var));  //init
        locked=0;

        int line=0;
        for(int i=1;i<=N;i++){
            gets(progm[line++]); id[i]=line-1;
            while(progm[line-1][2]!='d')
                gets(progm[line++]);
            ready.push_back(i);
        }
        while(!ready.empty()){
            int pid=ready.front(); ready.pop_front();
            run(pid);
        }
        if(T) printf("\n");
    }
    return 0;
}
