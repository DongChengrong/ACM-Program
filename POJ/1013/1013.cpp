#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int time[12];
int t[12];
char s[3][3][12];

int cmp(int s1,int s2)
{
    return abs(s1)>abs(s2);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++) scanf("%s%s%s",s[i][0],s[i][1],s[i][2]);
        for(int j=0;j<3;j++)
        {
            switch (s[i][2][0])
            {
                case 'e': break;
                case 'u':
                    {
                        for(int k=0;k<strlen(s[i][0]);k++)
                        {
                            time[s[i][0][k]-'A']++;
                            time[s[i][1][k]-'A']--;
                        }
                        break;
                    }
                case 'd':
                    {
                         for(int k=0;k<strlen(s[i][0]);k++)
                         {
                            time[s[i][0][k]-'A']--;
                            time[s[i][1][k]-'A']++;
                         }
                        break;
                    }
            }
        }
        memcpy(t,time,sizeof(t));
        sort(t,t+11,cmp);
        int k=t[0];
        for(int j=0;j<11;j++) { if(time[j]==k) { printf("%c",'A'+j); break; } }
    }
    return 0;
}
