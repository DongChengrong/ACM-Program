#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<sstream>
using namespace std;

const int maxm=100;
const int maxn=100000;
queue<string> pro[maxn];
deque<int> run,stop;
int m[50];
int t[5];
int N,T,lock;
char order[maxm];

void init(){
    memset(m,0,sizeof(m));
    run.clear(); stop.clear();
    for(int i=1;i<=N;i++){ while(!pro[i].empty()) pro[i].pop();}
}

int action(string order,int state)
{
    string s;
    stringstream ss(order);
    ss>>s;
    if(s=="lock"){
        if(lock) { stop.push_back(state); run.pop_back(); return T+1; }
        else{
            lock=state;
            pro[state].pop();
            return t[2];
        }
    }else if(s=="unlock"){
        lock=0; pro[state].pop();
        if(!stop.empty()){
            int i=stop.front(); stop.pop_front();
            run.push_front(i);
        }
        return t[3];
    }else if(s=="print"){
        pro[state].pop();
        ss>>s; printf("%d: %d\n",state,m[s[0]-'a']);
        return t[1];
    }else{
        pro[state].pop();
        if(lock && lock!=state) return t[0];
        string sss; ss>>sss;
        int n; ss>>n;
        m[s[0]-'a']=n;
        return t[0];
    }
}

int main()
{
    int Test,flag=0;
    scanf("%d",&Test);
    while(Test--){
        init();
        getchar();
        if(flag) printf("\n"); flag=1;
        scanf("%d",&N);
        for(int i=0;i<5;i++) scanf("%d",&t[i]);
        scanf("%d",&T); getchar();
        lock=0;
        for(int i=1;i<=N;i++)
        {
            while(gets(order))
            {
                string s=""; s+=order;
                pro[i].push(s);
                if(s=="end") break;
            }
            run.push_back(i);
        }
        while(!run.empty())
        {
            string s;
            int time=T;
            int state=run.front(); run.pop_front(); run.push_back(state);
            while(time>0)
            {
                s=pro[state].front();
                if(s=="end")  { run.pop_back(); break;}
                else time-=action(s,state);
            }
        }
    }
    return 0;
}
