#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define N 1100

typedef long long ll;

int cmd;  //����ѡ��
char a[N], b[N]; //�ÿ�ѧ��������A��B

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void menu() {   //���˵�
    system("cls");
    printf("\t\t\t\t\t\t���˵�\n");
    printf("\t\t\t\t\t\t1��Ҫ���\n");
    printf("\t\t\t\t\t\t2��Ҫ����\n");
    printf("\t\t\t\t\t\t3��Ҫ����\n");
    printf("\t\t\t\t\t\t4��Ҫ����\n");
    printf("\t\t\t\t\t\t5��Ҫ����\n");
    printf("\t\t\t\t\t\t6��Ҫ����\n");
    printf("\t\t\t\t\t\t7����ѧ������\n");
    printf("\t\t\t\t\t\t8����Ƕ�\n");
    printf("\t\t\t\t\t\t0���˳�\n");
}

void sub_menu() {   //�Ӳ˵�
    system("cls");
    printf("\t\t\t\t\t\t�Ӳ˵�\n");
    printf("\t\t\t\t\t\t1���ӷ�\n");
    printf("\t\t\t\t\t\t2������\n");
    printf("\t\t\t\t\t\t3���˷�\n");
    printf("\t\t\t\t\t\t4������\n");
    printf("\t\t\t\t\t\t0���������˵�\n");
    printf("���������ѡ��");
}

double add() {  //�ӷ�
    fflush(stdin);  //��ջ�����
    double x, y;
    printf("��������������\n");
    scanf("%lf%lf",&x, &y);
    return x + y;
}

double dif() {  //����
    fflush(stdin);  //��ջ�����
    double x, y;
    printf("��������������\n");
    scanf("%lf%lf",&x, &y);
    return x - y;
}

double mul() {  //�˷�
    fflush(stdin);  //��ջ�����
    double x, y;
    printf("��������������\n");
    scanf("%lf%lf",&x, &y);
    return x * y;
}

double div() {  //����
    fflush(stdin);  //��ջ�����
    double x, y;
    while (1) {
        printf("��������������\n");
        scanf("%lf%lf",&x, &y);
        if (y != 0) break;
        else printf("�������ܵ���0");
    }
    return x / y;
}

void run1() {   //Ҫ�������
    fflush(stdin);  //��ջ�����
    double res;  //�����Ľ��
    while (1) {
        sub_menu();
        scanf("%d",&cmd);
        switch (cmd) {
            case 1: {
                res = add(); break;  //��
            }
            case 2: {
                res = dif(); break;  //��
            }
            case 3: {
                res = mul(); break;  //��
            }
            case 4: {
                res = div(); break;  //��
            }
            case 0: {  //�˳�
                return;
            }
            default : {
                printf("�޸�ѡ�������ѡ��");
                system("pause");
            }
        }
        printf("�����Ľ��Ϊ%.0f\n",res);
        system("pause");
    }
}

void run2() {   //Ҫ����
    fflush(stdin);  //��ջ�����
    double res;  //�����Ľ��
    while (1) {
        sub_menu();
        scanf("%d",&cmd);
        switch (cmd) {
            case 1: {
                res = add(); break;  //��
            }
            case 2: {
                res = dif(); break;  //��
            }
            case 3: {
                res = mul(); break;  //��
            }
            case 4: {
                res = div(); break;  //��
            }
            case 0: {  //�˳�
                return;
            }
            default : {
                printf("�޸�ѡ�������ѡ��");
                system("pause");
            }
        }
        int pre, suf;
        pre = (int)res % 10000;  //С����ǰ��λ����
        suf = (int)((res - (int)res) * 10000 ); //С�������λ����
        printf("�����Ľ��Ϊ%d.%d\n",pre, suf);
        system("pause");
    }
}

void run4() {  //Ҫ����
    fflush(stdin);  //��ջ�����
    double x;
    printf("������һ������");
    scanf("%lf",&x);
    x = sqrt(x);
    printf("���Ϊ%.4f\n",x);
    system("pause");
}

/*
���ǵ�����̨����û�а���������������ʱ����ģ��
*/
void run5() {  //Ҫ����
    int pre, suf;
    char c;
    fflush(stdin);  //��ջ�����
    printf("������һ������"); scanf("%d",&pre);
    printf("�����������"); fflush(stdin); scanf("%c",&c);
    printf("������һ������"); scanf("%d",&suf);
    if (c == '+') pre = pre + suf;
    if (c == '-') pre = pre - suf;
    if (c == '*') pre = pre * suf;
    if (c == '/') pre = pre / suf;
    printf("������һ�������"); fflush(stdin); scanf("%c",&c);
    printf("������һ������"); scanf("%d",&suf);
    if (c == '+') pre = pre + suf;
    if (c == '-') pre = pre - suf;
    if (c == '*') pre = pre * suf;
    if (c == '/') pre = pre / suf;
    printf("�����%d\n",pre);
    system("pause");
}

/*
���߸�Ҫ����Ҫ���ɷ��ӣ���������ѡ�������Բ�����Ϊ�ҵ��о�����
�������Բ��Ե���ϸ���ܲμ���
baike.baidu.com/item/%E7%B4%A0%E6%80%A7%E6%B5%8B%E8%AF%95/9037686?fr=aladdin
�������Ҽ�Ҫ˵��һ��
��������һ����������������������һ�����������1���������0
*/
void run6() {
    int x;
    fflush(stdin);  //��ջ�����
    while (1) {
        printf("������һ��������\n");
        scanf("%d",&x);
        if (x >= 1) break;
        else printf("�����������������������������\n");
    }
    if (is_prime(x)) puts("1");
    else puts("0");
    system("pause");
}

void run7() {
    double a, b;
    char cmd;
    fflush(stdin);
    printf("��ֱ�������������");
    scanf("%lf",&a);
    scanf("%lf",&b);
    fflush(stdin);
    printf("�����������:"); fflush(stdin);
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
    printf("������Ƕ�");
    scanf("%lf",&x);
    x = x * 3.14 / 180;
    printf("sin%.4f=%.1f\n",x,sin(x));
    system("pause");
}

int main() {
    while (1) {
        menu();
        printf("����������ѡ��"); scanf("%d",&cmd); //��ȡѡ��
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
                printf("�޸�ѡ�������ѡ��");
                system("pause"); break;
            }
        }
    }
    return 0;
}
