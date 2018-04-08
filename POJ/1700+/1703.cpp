/*
���ò��鼯��ά����ͬ����֮��Ĺ�ϵ
�˷�����������ֻ���������ϵ����
���ǿ�����x + n����ʾx�Ĳ�ͬ����
�����Ļ������x��y�ǲ�ͬ�ļ�����x+n��y����ͬһ������
y+n��x���ڲ�ͬ����
������������ͬһ�����ϵ��ҽ���Same(x,y)��Same(x+n,y+n)����ʱ
�������ϲ�����ͬһ������ʱ�����ҽ���Same(x+n,y)��Same(x,y+n)����ʱ
����x��y��״̬δȷ��
*/

#include<stdio.h>

#define N (2 * 100100)

int pa[N];

void init(int n){
    for(int i = 0; i <= 2 * n; i++)
        pa[i] = i;
}

int findset(int x){
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

void Union(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if(x != y)
        pa[x] = y;
}

bool Same(int x, int y)
{
    x = findset(x);
    y = findset(y);
    return x == y;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init(n);
        while(m--)
        {
            char c;
            int x,y;
            getchar();
            scanf("%c %d %d",&c,&x,&y);
            if(c == 'D')
            {
                Union(x,y+n);
                Union(x+n,y);
            }
            if(c == 'A')
            {
                if(Same(x,y) || Same(x+n,y+n)) printf("In the same gang.\n");
                else if(Same(x,y+n) || Same(x+n,y)) printf("In different gangs.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}

