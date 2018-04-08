/*STL ���ȶ���*/

//Memory Time
//512K   47MS

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�ȽϹ�����С����
class cmp
{
public:
    bool operator()(const __int64 a,const __int64 b)const
    {
        return a>b;
    }
};

int main(void)
{
    int n;  //��Ҫ�и��ľ�����
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //�������ȶ���

        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //����Ҫ���ľ�峤�ȣ����ã������
        }

        __int64 mincost=0;   //��С����
        while(Queue.size()>1)  //��������С�ڵ���һ��Ԫ��ʱ����
        {
            __int64 a=Queue.top();  //�õ�����Ԫ�ص�ֵ����ʹ�����
            Queue.pop();
            __int64 b=Queue.top();  //����ȡ���ף����õ���С������ֵ
            Queue.pop();

            Queue.push(a+b);  //���
            mincost+=a+b;
        }
        printf("%I64d\n",mincost);

        while(!Queue.empty())  //��ն���
            Queue.pop();
    }
    return 0;
}
