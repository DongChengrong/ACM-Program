#include<stdio.h>
#include<string.h>
int mark=0;

void dushu(char *str)
{
    switch (str[0])
    {
        case '1':
           printf("һ");
           break;
       case '2':
           printf("��");
           break;
        case '3':
           printf("��");
           break;
       case '4':
           printf("��");
           break;
         case '5':
           printf("��");
           break;
       case '6':
           printf("��");
           break;
        case '7':
           printf("��");
           break;
       case '8':
           printf("��");
           break;
       case '9':
           printf("��");
           break;
    }
}
void panduan(char *str)
{
    int i;
    i=strlen(str);
    if(str[0]=='0')
    {
        if(mark=0)
        {
            if(i+1>=5)
                printf("��");
            mark=1;
        }
    }
    if(str[0]!='0')
    {
        if(mark=1)
            mark=0;
        dushu(str);
    }
    switch (i)
    {
       case 2:
           printf("ʮ");
           break;
        case 3:
           printf("��");
           break;
       case 4:
           printf("ǧ");
           break;
         case 5:
           printf("��");
           break;
       case 6:
           printf("ʮ��");
           break;
        case 7:
           printf("����");
           break;
       case 8:
           printf("ǧ��");
           break;
       case 9:
           printf("��");
           break;
    }
    if(i!=1)
       panduan(str+1);
}

int main()
{
    char str[20];
    while(~scanf("%s",str))
    {
        panduan(str);
        printf("\n");
    }
    return 0;
}
