#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 1000 + 10;

vector<int> G[maxn];  //记录无根树（即多条边）
int p[maxn];   //某一节点的父节点，-1代表没有节点

//读取无根树
void read_tree()
{
    int u,v,n;
    printf("请输入节点的个数");
    scanf("%d",&n);
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

//利用深搜将无根树转换为有根数
//为了验证程序的正确性，我们边转换边输出结果
void dfs(int root, int pa)
{
    printf("%d\n",root);
    int d = G[root].size();
    for(int i = 0; i < d; i++)
    {
        int u = G[root][i];
        if(u != pa)
        {
            dfs(u,p[u] = root);
        }
    }
}

int main()
{
    while(1)
    {
        int stop,root;
        printf("是否终止程序？（1代表是，0代表否）");
        scanf("%d",&stop);
        if(stop == 1) break;

        read_tree();  //读取无根树
        printf("请选择一个节点作为根节点");
        scanf("%d",&root);
        dfs(root, p[root] = -1);   //利用深搜将无根树转换为有根数
    }
}
