/*STL 优先队列*/

//Memory Time
//512K   47MS

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//比较规则，最小优先
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
    int n;  //需要切割的木板个数
    while(cin>>n)
    {
        priority_queue<__int64,vector<__int64>,cmp>Queue;  //定义优先队列

        for(int i=1;i<=n;i++)
        {
            __int64 temp;
            scanf("%I64d",&temp);
            Queue.push(temp);       //输入要求的木板长度（费用）并入队
        }

        __int64 mincost=0;   //最小费用
        while(Queue.size()>1)  //当队列中小于等于一个元素时跳出
        {
            __int64 a=Queue.top();  //得到队首元素的值，并使其出队
            Queue.pop();
            __int64 b=Queue.top();  //两次取队首，即得到最小的两个值
            Queue.pop();

            Queue.push(a+b);  //入队
            mincost+=a+b;
        }
        printf("%I64d\n",mincost);

        while(!Queue.empty())  //清空队列
            Queue.pop();
    }
    return 0;
}
