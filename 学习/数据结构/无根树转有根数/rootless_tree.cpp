#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 1000 + 10;

vector<int> G[maxn];  //��¼�޸������������ߣ�
int p[maxn];   //ĳһ�ڵ�ĸ��ڵ㣬-1����û�нڵ�

//��ȡ�޸���
void read_tree()
{
    int u,v,n;
    printf("������ڵ�ĸ���");
    scanf("%d",&n);
    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

//�������ѽ��޸���ת��Ϊ�и���
//Ϊ����֤�������ȷ�ԣ����Ǳ�ת����������
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
        printf("�Ƿ���ֹ���򣿣�1�����ǣ�0�����");
        scanf("%d",&stop);
        if(stop == 1) break;

        read_tree();  //��ȡ�޸���
        printf("��ѡ��һ���ڵ���Ϊ���ڵ�");
        scanf("%d",&root);
        dfs(root, p[root] = -1);   //�������ѽ��޸���ת��Ϊ�и���
    }
}
