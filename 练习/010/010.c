#include<stdio.h>
#include<string.h>
int mark=0;

void dushu(char *str)
{
    switch (str[0])
    {
        case '1':
           printf("一");
           break;
       case '2':
           printf("二");
           break;
        case '3':
           printf("三");
           break;
       case '4':
           printf("四");
           break;
         case '5':
           printf("五");
           break;
       case '6':
           printf("六");
           break;
        case '7':
           printf("七");
           break;
       case '8':
           printf("八");
           break;
       case '9':
           printf("九");
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
                printf("零");
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
           printf("十");
           break;
        case 3:
           printf("百");
           break;
       case 4:
           printf("千");
           break;
         case 5:
           printf("万");
           break;
       case 6:
           printf("十万");
           break;
        case 7:
           printf("百万");
           break;
       case 8:
           printf("千万");
           break;
       case 9:
           printf("亿");
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
