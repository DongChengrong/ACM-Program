//ѧ���ɼ�����ϵͳ
//UVA12412
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define EPS 1e-5

//�Զ������ݽṹ
typedef struct Node
{
    char sid[15];
    int cid;
    char name[15];
    int language,math,english,programing;
    int sum_score;   //�����ܷ�
    float average_score;  //ƽ����
    int pass_number;   //����Ŀ�Ŀ����
}Node;

vector<Node> database; //�洢���ݵ����ݿ�

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

//����Ƿ����ظ�SID
int checkSID(char *info)
{
    for(int i=0;i<database.size();i++)
    {
        if(!strcmp(database[i].sid,info))
        {
            printf("Duplicated SID.\n");
            return 1;   //�����ظ���SIDʱ����1
        }
    }
    return 0;  //û���ظ���SID����0
}

//�����Ϣ����
void addInfo()
{
    Node u;
    while(1)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s",u.sid);   //¼��SID
        if(!strcmp(u.sid,"0")) return;   //�����0����
        scanf("%d",&u.cid);  //¼��CID
        scanf("%s",u.name);   //¼������
        scanf("%d%d%d%d",&u.language,&u.math,&u.english,&u.programing);   //¼�����ġ���ѧ��Ӣ����
        if(checkSID(u.sid)) continue;   //��֤�Ƿ����ظ���SID
        u.sum_score=u.language+u.english+u.math+u.programing;   //�����ܷ�
        u.average_score=((float)u.sum_score)/4.0;   //����ƽ����
        int pass_number=0;
        if(u.language>=60) pass_number++;
        if(u.math>=60) pass_number++;
        if(u.english>=60) pass_number++;
        if(u.programing>=60) pass_number++;
        u.pass_number=pass_number;
        database.push_back(u);    //���ظ��Ļ������ݴ洢�����ݿ���
    }
}

int deleteFromDB(char *s)
{
    int count=0;  //����ͳ��ɾ���˼�����Ϣ
    for(int i=0;i<database.size();i++)
    {
        if(!strcmp(s,database[i].sid) || !strcmp(s,database[i].name))
        {
            database.erase(database.begin()+i);   //�����ݿ��а�Ҫɾ��������ɾ��
            count++;
        }
    }
    return count;
}

//����ѧ��SID�����������ݿ���ɾ����Ϣ
void removeInfo()
{
    char s[30];   //SID������
    while(1)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",s);
        if(!strcmp(s,"0")) return;   //�ǽ�����־�˳�
        printf("%d student(s) removed.\n",deleteFromDB(s));   //ɾ����������
    }
}

//�����ֵܷó��꼶����
int ranked(int sum_score)
{
    int ranked=1;   //��ʼ������Ϊ1
    for(int i=0;i<database.size();i++)
    {
        //����бȸ��ִܷ�ķ�����������1
        if(sum_score<database[i].sum_score)
            ranked++;
    }
    return ranked;   //��������
}

//����SID����������ѯѧ����Ϣ
void query()
{
    char s[30];  //SID���������������־
    while(1)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",s);
        if(!strcmp("0",s)) return;
        //�����ݿ��в���ƥ�����Ϣ����ӡ
        for(int i=0;i<database.size();i++)
        {
            Node u=database[i];   //��ȡ��ǰ������
            if(!strcmp(s,u.sid) || !strcmp(s,u.name))
            {
                printf("%d %s %d %s %d %d %d %d %d %.2f\n",ranked(u.sum_score),u.sid,u.cid,u.name,u.language,u.math,u.english,u.programing,u.sum_score,u.average_score+EPS);
            }
        }
    }
}

//����CID��ӡ��һ����״̬
void showPart1(int cid)
{
    int number=0;  //ָ���༶��ѧ������
    int language_sum=0,language_pass=0,language_unpass=0;  //�����������õ��ı�������ͬ
    int math_sum=0,math_pass=0,math_unpass=0;
    int english_sum=0,english_pass=0,english_unpass=0;
    int programing_sum=0,programing_pass=0,programing_unpass=0;
    for(int i=0;i<database.size();i++)
    {
        Node u=database[i];
        if(cid!=0 && cid!=u.cid) continue;
        number++;
        //ͳ�Ƹ��Ƽ������
        if(u.language>=60) language_pass++;
        else language_unpass++;
        if(u.math>=60) math_pass++;
        else math_unpass++;
        if(u.english>=60) english_pass++;
        else english_unpass++;
        if(u.programing>=60) programing_pass++;
        else programing_unpass++;
        //��������ܷ�
        language_sum+=u.language;
        math_sum+=u.math;
        english_sum+=u.english;
        programing_sum+=u.programing;
    }
    printf("Chinese\n");
    printf("Average Score: %.2f\n",number==0?0:((float)language_sum)/(float)number+EPS);
    printf("Number of passed students: %d\n",language_pass);
    printf("Number of failed students: %d\n\n",language_unpass);
    printf("Mathematics\n");
    printf("Average Score: %.2f\n",number==0?0:((float)math_sum)/(float)number+EPS);
    printf("Number of passed students: %d\n",math_pass);
    printf("Number of failed students: %d\n\n",math_unpass);
    printf("English\n");
    printf("Average Score: %.2f\n",number==0?0:((float)english_sum)/(float)number+EPS);
    printf("Number of passed students: %d\n",english_pass);
    printf("Number of failed students: %d\n\n",english_unpass);
    printf("Programming\n");
    printf("Average Score: %.2f\n",number==0?0:((float)programing_sum)/(float)number+EPS);
    printf("Number of passed students: %d\n",programing_pass);
    printf("Number of failed students: %d\n\n",programing_unpass);
}

//����CID��ʾ�ڶ�����״̬
void showPart2(int cid)
{
    int pass0,pass1,pass2,pass3,pass4;   //�ֱ��Ӧͨ��0,1,2,3,4�Ƶ�ѧ������
    pass0=pass1=pass2=pass3=pass4=0; //ȫ����ʼ��Ϊ0
    for(int i=0;i<database.size();i++)
    {
        Node u=database[i];
        if(cid!=0 && cid!=u.cid) continue;
        switch (u.pass_number)
        {
            case 0:
            {
                pass0++;
                break;
            }
            case 1:
            {
                pass1++;
                break;
            }
            case 2:
            {
                pass2++;
                break;
            }
            case 3:
            {
                pass3++;
                break;
            }
            case 4:
            {
                pass4++;
                break;
            }
        }
    }
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n",pass4);
    printf("Number of students who passed 3 or more subjects: %d\n",pass3+pass4);
    printf("Number of students who passed 2 or more subjects: %d\n",pass2+pass3+pass4);
    printf("Number of students who passed 1 or more subjects: %d\n",pass1+pass2+pass3+pass4);
    printf("Number of students who failed all subjects: %d\n\n",pass0);
}

//����CID��ʾ״̬
void showStatistics()
{
    int cid;  //�꼶���
    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%d",&cid);
    showPart1(cid);
    showPart2(cid);
}

//ѡ��˵�
void menu()
{
    int choice;  //ѡ��
    while(1)
    {
        screen();   //��ʾ���˵�
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                addInfo();  //�����Ϣ����
                break;
            }
            case 2:
            {
                removeInfo();   //ɾ����Ϣ����
                break;
            }
            case 3:
            {
                query();
                break;
            }
            case 4:
            {
                printf("Showing the ranklist hurts students�� self-esteem. Don��t do that.\n");
                break;
            }
            case 5:
            {
                showStatistics();
                break;
            }
            case 0:
            {
                return;
            }
        }
    }
}

int main()
{
    menu();   //ѡ��˵�
    return 0;
}
