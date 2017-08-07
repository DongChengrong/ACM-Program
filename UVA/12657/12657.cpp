#include<cstdio>
#include<cstdlib>
using namespace std;

int reverse;

typedef struct Node{
    int id;
    struct Node *pre,*next;
}Node,*LNode;

void init(LNode &head,int n,LNode &rear){
    head=(LNode)malloc(sizeof(Node));
    head->id=-1; head->pre=NULL;
    rear=(LNode)malloc(sizeof(Node));
    rear->id=-1; rear->next=NULL;
    head->next=rear; rear->pre=head;
    for(int i=1;i<=n;i++){
        LNode p=(LNode)malloc(sizeof(Node));
        p->next=rear; p->pre=rear->pre;
        rear->pre->next=p; rear->pre=p;
        p->id=i;
    }
}

int locate(LNode L,LNode &p,LNode &q,int x,int y){
    LNode k=L->next;
    int num=0;
    while(k->id!=-1 && num!=2){
        if(k->id==x) { p=k; num++; }
        if(k->id==y) { q=k; num++; }
        k=k->next;
    }
}

void right(LNode &head,int x,int y){
    LNode p,q;
    locate(head,p,q,x,y);
    if(q->next==p) return;  //if x is left to y,return!
    p->next->pre=p->pre; p->pre->next=p->next;
    q->next->pre=p; p->next=q->next; p->pre=q; q->next=p; //insert p into the q left
}
void left(LNode &head,int x,int y){
    LNode p,q;
    locate(head,p,q,x,y);
    if(q->pre==p) return; //if x is right to y,return!
    p->next->pre=p->pre; p->pre->next=p->next; //split p from chain
    q->pre->next=p; p->next=q; p->pre=q->pre; q->pre=p;
}

void replace(LNode &head,int x,int y){
    LNode p,q,k;
    locate(head,p,q,x,y);
    int temp=p->id;
    p->id=q->id;
    q->id=temp;
}
long long sum(LNode head,LNode rear){
    int i=1;
    long long ans=0;
    LNode p;
    if(!reverse){
        p=head->next;
        while(p->id!=-1){
        if(i%2) ans+=p->id;
        i++; p=p->next;
        }
    }
    else{
        p=rear->pre;
        while(p->id!=-1){
        if(i%2) ans+=p->id;
        i++; p=p->pre;
        }
    }
    return ans;
}

void print(LNode head){
    LNode p=head->next;
    while(p->id!=-1){
        printf("%d  ",p->id);
        p=p->next;
    }
    printf("\n");
}

int main(){
    int N,M,Test=1;
    while(scanf("%d %d",&N,&M)==2){
        LNode head,rear;
        init(head,N,rear);
        reverse=0;
        for(int i=1;i<=M;i++){
            int order;
            scanf("%d",&order);
            if(order==4) { reverse=!reverse; continue; }
            int x,y;
            scanf("%d %d",&x,&y);
            switch(order){
                case 1:
                    if(reverse) right(head,x,y);
                    else left(head,x,y);
                    break;
                case 2:
                    if(reverse) left(head,x,y);
                    else right(head,x,y);
                    break;
                case 3:
                    replace(head,x,y);
                    break;
            }
        }
        printf("Case %d: %lld\n",Test++,sum(head,rear));
    }
    return 0;
}
