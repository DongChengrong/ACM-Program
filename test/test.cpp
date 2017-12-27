#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  char name[80][12],tp1[12];
  int num[80],tp2;
  double score[80],tp3;
void Sort(int n)
{
    int i,j,max;
    for(i=1;i<n;i++)
    {   max=i;
        for(j=i+1;j<=n;j++)
        {
            if(score[max]<score[j])
            {
                max=j;
            }
        }
       strcpy(tp1,name[max]) ;
        strcpy(name[max],name[i]);
       strcpy( name[i],tp1);
        tp2=num[max];
        num[max]=num[i];
        num[i]=tp2;
        tp3=score[max];
        score[max]=score[i];
        score[i]=tp3;
    }

}
int main()
{   int i=0,j;
    FILE *fp;
    if((fp=fopen("test.txt","r+"))==NULL)
    {
        printf("Can't find this file");
        exit(0);
    }
    fseek(fp,0L,SEEK_SET);
    while(feof(fp)==0)
    {
        i++;
        fscanf(fp,"%s",name[i]);
        fscanf(fp,"%d",&num[i]);
        fscanf(fp,"%lf",&score[i]);
        if(i==1 || i==4 || i==6)
        {
            printf("%-10s\t%d\t%.2lf\n",name[i],num[i],score[i]);
        }
    }
    Sort(i);
    for(j=1;j<=i;j++)
    {
      printf("%-10s\t%d\t%.2lf\n",name[j],num[j],score[j]);
    }


    // printf("%d",);



    return 0;
}
