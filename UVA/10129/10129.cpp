#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn=1000+10;
int blocks;  //一共几个区域
int alp[27],used[27],root[27];
char s[maxn];

//使用并查集寻找树根
int find_root(int x)
{
    return root[x]==x?x:root[x]=find_root(root[x]);
}

//初始化
void init()
{
    blocks=26;
    memset(alp,0,sizeof(alp));
    memset(used,0,sizeof(used));
    for(int i=0;i<26;i++)
        root[i]=i;
}

int main()
{
    int T;  //测试案例数
    scanf("%d",&T);
    while(T--)
    {
        int n;
        init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            //确定首尾字母
            int pos1=s[0]-'a'; int pos2=s[strlen(s)-1]-'a';
            //将节点标注为已使用
            used[pos1]=used[pos2]=1;
            //对度进行处理
            alp[pos1]++; alp[pos2]--;
            //寻找两个树根
            int root1=find_root(pos1);
            int root2=find_root(pos2);
            //确定是否是同一区域
            if(root1!=root2)
            {
                root[root1]=root2;
                blocks--;
            }
        }

        vector<int> v;
        for(int i=0;i<26;i++)
        {
            if(!used[i]) blocks--;
            if(alp[i]!=0) v.push_back(alp[i]);
        }
        int ok=0;
        if(blocks==1 && (v.empty() || (v.size()==2 && (v[0]==1 || v[0]==-1 ) )))
            ok=1;
        if(ok) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
