#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define EPS 1e-5
const int maxn=1000;
const int maxl=100;
int n=0;
char sid[maxn][maxl];
char name[maxn][maxl];
int removed[maxn];
int cid[maxn];
int score[maxn][5];

const char *course[]={"Chinese","Mathematics","English","Programming"};

//����Ƿ����ظ���SID
int valid(int k)
{
    for(int i=0;i<k;i++)
        if(!removed[i])
        {
            if(!strcmp(sid[i],sid[k])) return 0;
        }
    return 1;
}

//���ѧ����Ϣ
void addInfo()
{
    while(1)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s",sid[n]);
        if(!strcmp(sid[n],"0")) return;
        scanf("%d%s%d%d%d%d",&cid[n],name[n],&score[n][0],&score[n][1],&score[n][2],&score[n][3]);
        if(valid(n))
        {
            score[n][4]=score[n][0]+score[n][1]+score[n][2]+score[n][3];
            n++;
        }
        else printf("Duplicated SID.\n");

    }
}

//�õ�����
int ranked(int k)
{
    int r=0;
    for(int i=0;i<n;i++)
        if(!removed[i] && score[i][4]>score[k][4]) r++;
    return r+1;
}

//��ѯ��ɾ������
void DQ(int way)
{
    char s[maxl];
    while(1)
    {
        int r=0;
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",s);
        if(!strcmp(s,"0")) return;
        for(int i=0;i<n;i++)
        {
            if(removed[i]) continue;
            if(strcmp(sid[i],s)==0 || strcmp(name[i],s)==0)
            {
                if(way==1) { removed[i]=1; r++; }
                else
                {
                    printf("%d %s %d %s %d %d %d %d %d %.2f\n",ranked(i),sid[i],cid[i],name[i],score[i][0],score[i][1],score[i][2],score[i][3],score[i][4],score[i][4]/4.0+EPS);
                }
            }
        }
        if(way==1) printf("%d student(s) removed.\n",r);
    }
}

//�õ��γ�ͳ��
void getCourseStat(int c,int k)
{
    int pass,unpass,sum;
    pass=unpass=sum=0;
    for(int i=0;i<n;i++)
    {
        if(removed[i]) continue;
        if(c==0 || cid[i]==c)
        {
            sum+=score[i][k];
            if(score[i][k]>=60) pass++;
            else unpass++;
        }
    }
    printf("%s\n",course[k]);
    printf("Average Score: %.2f\n",(double)sum/(double)(pass+unpass)+EPS);
    printf("Number of passed students: %d\n",pass);
    printf("Number of failed students: %d\n\n",unpass);
}

//�õ�����ͳ��
void getOverallStat(int c)
{
    int pass[5];
    pass[0]=pass[1]=pass[2]=pass[3]=pass[4]=0;
    for(int i=0;i<n;i++)
    {
        if(removed[i]) continue;
        if(c==0 || c==cid[i])
        {
            int k=0;
            for(int j=0;j<4;j++)
                if(score[i][j]>=60) k++;
            pass[k]++;
        }
    }
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n",pass[4]);
    printf("Number of students who passed 3 or more subjects: %d\n",pass[3]+pass[4]);
    printf("Number of students who passed 2 or more subjects: %d\n",pass[2]+pass[3]+pass[4]);
    printf("Number of students who passed 1 or more subjects: %d\n",pass[1]+pass[2]+pass[3]+pass[4]);
    printf("Number of students who failed all subjects: %d\n\n",pass[0]);
}

//ͳ����Ϣ
void stat()
{
    int c;
    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%d",&c);
    for(int i=0;i<4;i++)
        getCourseStat(c,i);
    getOverallStat(c);
}

//��ʾ��Ļ
void screen()
{
    printf("Welcome to Student Performance Management System (SPMS).\n\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n\n");
}

//ѡ��˵�
void menu()
{
    int choice;  //ѡ��
    while(1)
    {
        screen();   //��ʾ���˵�
        scanf("%d",&choice);
        if(choice==0) return;
        if(choice==1) addInfo();
        if(choice==2) DQ(1);
        if(choice==3) DQ(2);
        if(choice==4) printf("Showing the ranklist hurts students�� self-esteem. Don��t do that.\n");
        if(choice==5) stat();
    }
}

int main()
{
    memset(removed,0,sizeof(removed));
    menu();
    return 0;
}
