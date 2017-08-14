#include<stdio.h>

int main()
{
    for(int row = 1;row<=9;row++)
    {
        for(int column = 1;column<=row;column++)
        {
            printf("%d * %d = %d  ",column,row,column * row);
        }
        printf("\n");
    }
    return 0;
}


