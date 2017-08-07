#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-5;
const int maxn = 1024;
int cnt = 0;

struct stu{
    string SID, name;
    int CID;
    int score[5];
    bool removed;
}all[maxn];

void print_menu()
{
    cout << "Welcome to Student Performance Management System (SPMS)." << endl << endl;
    cout << "1 - Add" << endl;
    cout << "2 - Remove" << endl;
    cout << "3 - Query" << endl;
    cout << "4 - Show ranking" << endl;
    cout << "5 - Show Statistics" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

int Rank(const int x)
{
    int t = all[x].score[0];
    int high = 0;
    for(int i = 0; i < cnt; i++)
        if(!all[i].removed && all[i].score[0] > t)
            high++;
    return high + 1;
}

void add()
{
    while(true){
        loop:
        cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
        stu in; cin >> in.SID;
        if(in.SID == "0") break;
        cin >> in.CID >> in.name >> in.score[1] >> in.score[2] >> in.score[3] >> in.score[4];
        for(int i = 0; i < cnt; i++)
            if(!all[i].removed && in.SID == all[i].SID){
                cout << "Duplicated SID." << endl;
                goto loop;
            }
        in.score[0] = in.score[1] + in.score[2] + in.score[3] + in.score[4];
        in.removed = false;
        all[cnt++] = in;
    }
}

void DQ(const int isq)
{
    while(true){
        cout << "Please enter SID or name. Enter 0 to finish." << endl;
        string str; cin >> str;
        if(str == "0") break;
        int rem_cnt = 0;
        for(int i = 0; i < cnt; i++){
            if(!all[i].removed && (str == all[i].SID || str == all[i].name)) {
                if(isq){
                    printf("%d %s %d %s %d %d %d %d %d %.2f\n", Rank(i), all[i].SID.c_str(), all[i].CID, all[i].name.c_str(),
                           all[i].score[1], all[i].score[2], all[i].score[3], all[i].score[4], all[i].score[0], all[i].score[0]/4.0+EPS);
                }
                else{
                    all[i].removed = true;
                    rem_cnt++;
                }
            }
        }
        if(!isq) printf("%d student(s) removed.\n", rem_cnt);
    }
}

void output(const int ID, const int type)
{
    int sum = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < cnt; i++){
        if(!all[i].removed && (ID==0 || all[i].CID==ID)){
            sum += all[i].score[type];
            if(all[i].score[type] >= 60) cnt1++;
            else cnt2++;
        }
    }
    printf("Average Score: %.2f\n", cnt1+cnt2 == 0 ? 0 : sum*1.0/(cnt1+cnt2)+EPS);
    printf("Number of passed students: %d\n", cnt1);
    printf("Number of failed students: %d\n", cnt2);
    printf("\n");
}

void stat()
{
    puts("Please enter class ID, 0 for the whole statistics.");
    int ID; cin >> ID;
    cout << "Chinese" << endl; output(ID, 1);
    cout << "Mathematics" << endl; output(ID, 2);
    cout << "English" << endl; output(ID, 3);
    cout << "Programming" << endl; output(ID, 4);
    cout << "Overall:" << endl;
    int okcnt[5]; memset(okcnt, 0, sizeof(okcnt));
    for(int i = 0; i < cnt; i++){
        if(!all[i].removed && (ID==0 || all[i].CID==ID)){
            int ok = 0;
            for(int j = 1; j <= 4; j++)
                if(all[i].score[j] >= 60)
                    ok++;
            okcnt[ok]++;
        }
    }
    printf("Number of students who passed all subjects: %d\n", okcnt[4]);
    printf("Number of students who passed 3 or more subjects: %d\n", okcnt[3]+okcnt[4]);
    printf("Number of students who passed 2 or more subjects: %d\n", okcnt[2]+okcnt[3]+okcnt[4]);
    printf("Number of students who passed 1 or more subjects: %d\n", okcnt[1]+okcnt[2]+okcnt[3]+okcnt[4]);
    printf("Number of students who failed all subjects: %d\n", okcnt[0]);
    printf("\n");
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(true){
        print_menu();
        int choice; cin >> choice;
        if(choice == 0) break;
        if(choice == 1) add();
        if(choice == 2) DQ(0);
        if(choice == 3) DQ(1);
        if(choice == 4) cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
        if(choice == 5) stat();
    }
    return 0;
}

