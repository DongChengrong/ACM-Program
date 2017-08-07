//学生成绩管理系统
//UVA12412
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define EPS 1e-5

//自定义数据结构
typedef struct Node
{
    char sid[15];
    int cid;
    char name[15];
    int language,math,english,programing;
    int sum_score;   //各科总分
    float average_score;  //平均分
    int pass_number;   //及格的科目数量
}Node;

vector<Node> database; //存储数据的数据库

//显示屏幕
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

//检查是否有重复SID
int checkSID(char *info)
{
    for(int i=0;i<database.size();i++)
    {
        if(!strcmp(database[i].sid,info))
        {
            printf("Duplicated SID.\n");
            return 1;   //当有重复的SID时返回1
        }
    }
    return 0;  //没有重复的SID返回0
}

//添加信息功能
void addInfo()
{
    Node u;
    while(1)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s",u.sid);   //录入SID
        if(!strcmp(u.sid,"0")) return;   //如果是0返回
        scanf("%d",&u.cid);  //录入CID
        scanf("%s",u.name);   //录入姓名
        scanf("%d%d%d%d",&u.language,&u.math,&u.english,&u.programing);   //录入语文、数学、英语、编程
        if(checkSID(u.sid)) continue;   //验证是否有重复的SID
        u.sum_score=u.language+u.english+u.math+u.programing;   //计算总分
        u.average_score=((float)u.sum_score)/4.0;   //计算平均分
        int pass_number=0;
        if(u.language>=60) pass_number++;
        if(u.math>=60) pass_number++;
        if(u.english>=60) pass_number++;
        if(u.programing>=60) pass_number++;
        u.pass_number=pass_number;
        database.push_back(u);    //不重复的话把数据存储到数据库中
    }
}

int deleteFromDB(char *s)
{
    int count=0;  //用来统计删除了几行信息
    for(int i=0;i<database.size();i++)
    {
        if(!strcmp(s,database[i].sid) || !strcmp(s,database[i].name))
        {
            database.erase(database.begin()+i);   //从数据库中把要删除的数据删除
            count++;
        }
    }
    return count;
}

//根据学生SID或姓名从数据库中删除信息
void removeInfo()
{
    char s[30];   //SID或姓名
    while(1)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",s);
        if(!strcmp(s,"0")) return;   //是结束标志退出
        printf("%d student(s) removed.\n",deleteFromDB(s));   //删除并输出结果
    }
}

//根据总分得出年级排名
int ranked(int sum_score)
{
    int ranked=1;   //初始化排名为1
    for(int i=0;i<database.size();i++)
    {
        //如果有比该总分大的分数，排名加1
        if(sum_score<database[i].sum_score)
            ranked++;
    }
    return ranked;   //返回排名
}

//根据SID或者姓名查询学生信息
void query()
{
    char s[30];  //SID或者姓名或结束标志
    while(1)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",s);
        if(!strcmp("0",s)) return;
        //在数据库中查找匹配的信息并打印
        for(int i=0;i<database.size();i++)
        {
            Node u=database[i];   //获取当前行数据
            if(!strcmp(s,u.sid) || !strcmp(s,u.name))
            {
                printf("%d %s %d %s %d %d %d %d %d %.2f\n",ranked(u.sum_score),u.sid,u.cid,u.name,u.language,u.math,u.english,u.programing,u.sum_score,u.average_score+EPS);
            }
        }
    }
}

//根据CID打印第一部分状态
void showPart1(int cid)
{
    int number=0;  //指定班级的学生人数
    int language_sum=0,language_pass=0,language_unpass=0;  //关于语文所用到的变量，下同
    int math_sum=0,math_pass=0,math_unpass=0;
    int english_sum=0,english_pass=0,english_unpass=0;
    int programing_sum=0,programing_pass=0,programing_unpass=0;
    for(int i=0;i<database.size();i++)
    {
        Node u=database[i];
        if(cid!=0 && cid!=u.cid) continue;
        number++;
        //统计各科及格情况
        if(u.language>=60) language_pass++;
        else language_unpass++;
        if(u.math>=60) math_pass++;
        else math_unpass++;
        if(u.english>=60) english_pass++;
        else english_unpass++;
        if(u.programing>=60) programing_pass++;
        else programing_unpass++;
        //计算各科总分
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

//根据CID显示第二部分状态
void showPart2(int cid)
{
    int pass0,pass1,pass2,pass3,pass4;   //分别对应通过0,1,2,3,4科的学生数量
    pass0=pass1=pass2=pass3=pass4=0; //全部初始化为0
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

//根据CID显示状态
void showStatistics()
{
    int cid;  //年级编号
    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%d",&cid);
    showPart1(cid);
    showPart2(cid);
}

//选择菜单
void menu()
{
    int choice;  //选项
    while(1)
    {
        screen();   //显示主菜单
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {
                addInfo();  //添加信息操作
                break;
            }
            case 2:
            {
                removeInfo();   //删除信息操作
                break;
            }
            case 3:
            {
                query();
                break;
            }
            case 4:
            {
                printf("Showing the ranklist hurts students’ self-esteem. Don’t do that.\n");
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
    menu();   //选择菜单
    return 0;
}
