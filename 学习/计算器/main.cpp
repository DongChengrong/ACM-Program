#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 1100

typedef long long ll;

int cmd;  //命令选项
char a[N], b[N]; //用科学计数法的A与B

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void menu() {   //主菜单
    system("cls");
    printf("\t\t\t\t\t\t主菜单\n");
    printf("\t\t\t\t\t\t1、要求二\n");
    printf("\t\t\t\t\t\t2、要求三\n");
    printf("\t\t\t\t\t\t3、要求四\n");
    printf("\t\t\t\t\t\t4、要求五\n");
    printf("\t\t\t\t\t\t5、要求六\n");
    printf("\t\t\t\t\t\t6、要求七\n");
    printf("\t\t\t\t\t\t7、科学计数法\n");
    printf("\t\t\t\t\t\t8、求角度\n");
    printf("\t\t\t\t\t\t0、退出\n");
}

void sub_menu() {   //子菜单
    system("cls");
    printf("\t\t\t\t\t\t子菜单\n");
    printf("\t\t\t\t\t\t1、加法\n");
    printf("\t\t\t\t\t\t2、减法\n");
    printf("\t\t\t\t\t\t3、乘法\n");
    printf("\t\t\t\t\t\t4、除法\n");
    printf("\t\t\t\t\t\t0、返回主菜单\n");
    printf("请输入你的选项");
}

double add() {  //加法
    fflush(stdin);  //清空缓冲区
    double x, y;
    printf("请输入两个数字\n");
    scanf("%lf%lf",&x, &y);
    return x + y;
}

double dif() {  //减法
    fflush(stdin);  //清空缓冲区
    double x, y;
    printf("请输入两个数字\n");
    scanf("%lf%lf",&x, &y);
    return x - y;
}

double mul() {  //乘法
    fflush(stdin);  //清空缓冲区
    double x, y;
    printf("请输入两个数字\n");
    scanf("%lf%lf",&x, &y);
    return x * y;
}

double div() {  //除法
    fflush(stdin);  //清空缓冲区
    double x, y;
    while (1) {
        printf("请输入两个数字\n");
        scanf("%lf%lf",&x, &y);
        if (y != 0) break;
        else printf("除数不能等于0");
    }
    return x / y;
}

void run1() {   //要求二、四
    fflush(stdin);  //清空缓冲区
    double res;  //运算后的结果
    while (1) {
        sub_menu();
        scanf("%d",&cmd);
        switch (cmd) {
            case 1: {
                res = add(); break;  //加
            }
            case 2: {
                res = dif(); break;  //减
            }
            case 3: {
                res = mul(); break;  //乘
            }
            case 4: {
                res = div(); break;  //除
            }
            case 0: {  //退出
                return;
            }
            default : {
                printf("无该选项，请重新选择！");
                system("pause");
            }
        }
        printf("运算后的结果为%.0f\n",res);
        system("pause");
    }
}

void run2() {   //要求三
    fflush(stdin);  //清空缓冲区
    double res;  //运算后的结果
    while (1) {
        sub_menu();
        scanf("%d",&cmd);
        switch (cmd) {
            case 1: {
                res = add(); break;  //加
            }
            case 2: {
                res = dif(); break;  //减
            }
            case 3: {
                res = mul(); break;  //乘
            }
            case 4: {
                res = div(); break;  //除
            }
            case 0: {  //退出
                return;
            }
            default : {
                printf("无该选项，请重新选择！");
                system("pause");
            }
        }
        int pre, suf;
        pre = (int)res % 10000;  //小数点前四位的数
        suf = (int)((res - (int)res) * 10000 ); //小数点后四位的数
        printf("运算后的结果为%d.%d\n",pre, suf);
        system("pause");
    }
}

void run4() {  //要求五
    fflush(stdin);  //清空缓冲区
    double x;
    printf("请输入一个数字");
    scanf("%lf",&x);
    x = sqrt(x);
    printf("结果为%.4f\n",x);
    system("pause");
}

/*
考虑到控制台程序没有按键，这里在输入时进行模拟
*/
void run5() {  //要求六
    int pre, suf;
    char c;
    fflush(stdin);  //清空缓冲区
    printf("请输入一个数字"); scanf("%d",&pre);
    printf("请输入运算符"); fflush(stdin); scanf("%c",&c);
    printf("请输入一个数字"); scanf("%d",&suf);
    if (c == '+') pre = pre + suf;
    if (c == '-') pre = pre - suf;
    if (c == '*') pre = pre * suf;
    if (c == '/') pre = pre / suf;
    printf("请输入一个运算符"); fflush(stdin); scanf("%c",&c);
    printf("请输入一个数字"); scanf("%d",&suf);
    if (c == '+') pre = pre + suf;
    if (c == '-') pre = pre - suf;
    if (c == '*') pre = pre * suf;
    if (c == '/') pre = pre / suf;
    printf("结果是%d\n",pre);
    system("pause");
}

/*
第七个要求需要自由发挥，在这里我选择了素性测试作为我的研究课题
关于素性测试的详细介绍参见：
baike.baidu.com/item/%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95/9037686?fr=aladdin
在这里我简要说明一下
首先输入一个正整数，如果这个数字是一个素数，输出1，否则输出0
*/
void run6() {
    int x;
    fflush(stdin);  //清空缓冲区
    while (1) {
        printf("请输入一个正整数\n");
        scanf("%d",&x);
        if (x >= 1) break;
        else printf("输入的数不是正整数，请重新输入\n");
    }
    if (is_prime(x)) puts("1");
    else puts("0");
    system("pause");
}

void run7() {
    double a, b;
    char cmd;
    fflush(stdin);
    printf("请分别输入两个数字");
    scanf("%lf",&a);
    scanf("%lf",&b);
    fflush(stdin);
    printf("请输入运算符:"); fflush(stdin);
    scanf("%c",&cmd);
    if (cmd == '+') a += b;
    if (cmd == '-') a -= b;
    if (cmd == '*') a *= b;
    if (cmd == '/') a /= b;
    int bit = 0;
    while (a >= 1) {
        a /= 10;
        bit++;
    }
    a *= 10; bit--;
    printf("%fE%d\n", a, bit);
    system("pause");
}

void run8() {
    double x;
    fflush(stdin);
    printf("请输入角度");
    scanf("%lf",&x);
    x = x * 3.14 / 180;
    printf("sin%.4f=%.1f\n",x,sin(x));
    system("pause");
}

int main() {
    while (1) {
        menu();
        printf("请输入您的选项"); scanf("%d",&cmd); //获取选项
        switch (cmd) {
            case 1: {
                run1(); break;
            }
            case 2: {
                run2(); break;
            }
            case 3: {
                run1(); break;
            }
            case 4: {
                run4(); break;
            }
            case 5: {
                run5(); break;
            }
            case 6: {
                run6(); break;
            }
            case 7: {
                run7(); break;
            }
            case 8: {
                run8(); break;
            }
            case 0: {
                return 0;
            }
            default : {
                printf("无该选项，请重新选择！");
                system("pause"); break;
            }
        }
    }
    return 0;
}
