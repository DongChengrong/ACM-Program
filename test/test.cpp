#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义数组的范围
#define MAXN 1000

//用于表达16进制的全部字符
char all_char[] = "0123456789ABCDEF";
char result[MAXN];   //最终结果
int tmp[MAXN];   //用来存储临时的值

//解决问题
//将一个16进制的数字转换成十进制，结果保存在result数组中
void slove(int x)
{
    int i;
    int cnt = 0;   //用于表示10进制数转换成多少位16进制数
    x = abs(x);   //得到x的绝对值
    while(x)
    {
        tmp[cnt++] = x % 16;
        x /= 16;
    }
    for(i = 0; i < cnt; i++)  //取反，在C语言中不允许在for循环中定义变量
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
        printf("请输入一个十进制负数:");
        scanf("%d",&x);
        slove(x);
        printf("该负数对应的十六进制为0x%s\n",result);
    }
    return 0;
}
