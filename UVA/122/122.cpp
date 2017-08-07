#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

const int maxn=300;
char s[maxn];
int flag;
typedef struct Node
{
    int data;
    struct Node *left,*right;
    Node():data(-1),left(NULL),right(NULL){}
}Node,*Tree;

Tree T;

Tree newNode()
{
    return new Node();
}

int check(Tree T,vector<Tree> &v)
{
    if(!flag) return 0;
    queue<Tree> q;
    if(T!=NULL) q.push(T);
    while(!q.empty())
    {
        Tree t=q.front(); q.pop();
        if(t->data==-1) return 0;
        else v.push_back(t);
        if(t->left!=NULL) q.push(t->left);
        if(t->right!=NULL) q.push(t->right);
    }
    return 1;
}
void removeTree(Tree T)
{
    if(T!=NULL)
    {
        removeTree(T->left);
        removeTree(T->right);
        delete T;
    }
}

int main()
{
    T=newNode();
    while(1)
    {
        Tree t;
        removeTree(T);
        flag=1; T=newNode();
        while(1)
        {
            if(scanf("%s",s)!=1) return 0;
            if(!strcmp(s,"()")) break;
            if(!flag) continue;
            int x,pos;
            x=s[1]-'0';
            for(pos=2;s[pos]!=',';pos++)
                x=x*10+(s[pos]-'0');
            t=T;
            for(int i=pos;s[i]!=')';i++)
            {
                if(s[i+1]==')')
                {
                    if(t->data!=-1) { flag=0; break; }
                    else t->data=x;
                }
                else
                {
                    if(s[i+1]=='L')
                    {
                        if(t->left==NULL) t->left=newNode();
                        t=t->left;
                    }
                    else if(s[i+1]=='R')
                    {
                        if(t->right==NULL) t->right=newNode();
                        t=t->right;
                    }
                }
            }
        }
        vector<Tree> v;
        if(!check(T,v)) printf("not complete\n");
        else
        {
            for(int i=0;i<v.size()-1;i++) printf("%d ",v[i]->data);
            printf("%d\n",v[v.size()-1]->data);
        }
    }
    return 0;
}
