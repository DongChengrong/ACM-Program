#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int h,m,s,t;
    int day = 0;
    string ss;
    cin >> ss;
    scanf("%d:%d:%d",&h,&m,&s);
    scanf("%d",&t);
    int cost = 0;   //������һ����Ҫ������
    cost = (23 - h) * 60 * 60 + (59 - m) * 60 + (60 - s);
    if(t < cost) day = 0;
    else
    {
        int d = 24 * 60 * 60;  //һ�칲�ж�����
        t -= cost;   //������һ���ʣ�µ�ʱ��
        day = 1;
        day += (t / d);
    }
    printf("%d\n",day);
    return 0;
}
