#include<stdio.h>
#include<string.h>

#define N 1000

char s[N];
double cnt1,cnt2,sum;

void dfs(char *s, double v, int i)
{
    if(i == strlen(s)){
        cnt2++;
        if(v == sum) cnt1++;
        return;
    }

    if(s[i] == '+') dfs(s,v+1,i+1);
    if(s[i] == '-') dfs(s,v-1,i+1);
    if(s[i] == '?'){
        dfs(s,v+1,i+1);
        dfs(s,v-1,i+1);
    }

}

int main()
{
    while(scanf("%s",s) == 1)
    {
        int i;
        sum = cnt1 = cnt2 = 0;
        for(int i = 0; i < strlen(s); i++)
            if(s[i] == '+') sum += 1;
            else sum -= 1;

        scanf("%s",s);

        dfs(s,0,0);

        printf("%.12lf\n",cnt1 / cnt2);
    }
    return 0;
}
