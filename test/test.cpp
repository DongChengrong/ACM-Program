#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��������ķ�Χ
#define MAXN 1000

//���ڱ��16���Ƶ�ȫ���ַ�
char all_char[] = "0123456789ABCDEF";
char result[MAXN];   //���ս��
int tmp[MAXN];   //�����洢��ʱ��ֵ

//�������
//��һ��16���Ƶ�����ת����ʮ���ƣ����������result������
void slove(int x)
{
    int i;
    int cnt = 0;   //���ڱ�ʾ10������ת���ɶ���λ16������
    x = abs(x);   //�õ�x�ľ���ֵ
    while(x)
    {
        tmp[cnt++] = x % 16;
        x /= 16;
    }
    for(i = 0; i < cnt; i++)  //ȡ������C�����в�������forѭ���ж������
        tmp[i] ^= tmp[i];
    for(i = 0; i < cnt; i++)
        result[i] = all_char[tmp[i]];
    result[cnt] = '\0';
}

int main()
{
    while(1)
    {
        int x;
        printf("������һ��ʮ���Ƹ���:");
        scanf("%d",&x);
        slove(x);
        printf("�ø�����Ӧ��ʮ������Ϊ0x%s\n",result);
    }
    return 0;
}
