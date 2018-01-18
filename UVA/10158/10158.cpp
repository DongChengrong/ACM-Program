#include<stdio.h>
#include<vector>
using namespace std;

const int maxn = 10000 + 10;
int n;
int pa[2 * maxn];    //ǰn�����������ѣ���n�����������

//��ʼ��
void init(int n)
{
    for(int i = 0; i < 2 * n; i++)   //����
        pa[i] = i;
}

//���鼯
int findset(int x)
{
    return pa[x] == x ? x : pa[x] = findset(pa[x]);
}

//��ȡ����
bool read_data(int &c, int &x, int &y)
{
    if(scanf("%d%d%d",&c,&x,&y) != 3)
        return false;
    if(c == 0)
        return false;
    return true;
}

//��������
void set_friends(int x, int y)
{
    int fx,fy;
    int ex,ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);

    if(fx == ey || fy == ex)
        printf("-1\n");
    else
    {
        pa[fx] = fy;
        pa[ex] = ey;
    }
}

//���õ���
void set_enemies(int x, int y)
{
    int fx,fy;
    int ex,ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);
    if(fx == fy)
        printf("-1\n");
    else
    {
        pa[fx] = ey;
        pa[fy] = ex;
    }
}

//�ǲ�������
void are_friends(int x, int y)
{
    int fx,fy;
    fx = findset(x); fy = findset(y);
    printf("%d\n",fx == fy ? 1 : 0);
}

//�ǲ��ǵ���
void are_enemies(int x, int y)
{
    int fx,fy;
    int ex, ey;
    fx = findset(x); fy = findset(y);
    ex = findset(x + n); ey = findset(y + n);
    if(fx == ey || fy == ex)
        printf("1\n");
    else
        printf("0\n");
}

void operate(int c, int x, int y)
{
    if(c == 1) set_friends(x,y);
    if(c == 2) set_enemies(x,y);
    if(c == 3) are_friends(x,y);
    if(c == 4) are_enemies(x,y);
}

int main()
{
    int c,x,y;
    scanf("%d",&n);
    init(n);
    while(read_data(c,x,y))    //���϶�ȡ��ִ��ָ��
        operate(c,x,y);
    return 0;
}
