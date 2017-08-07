#include<stdio.h>
#include<string.h>

int table[11];
char s[11];

int key(char *s){
    int sum=0,i;
    for(i=0;i<strlen(s);i++){
        sum+=(s[i]-'a');
    }
    return sum%11;
}

int main(){
    table[3]='D',table[10]='C',table[6]='R';
    while(scanf("%s",s)==1){
        printf("%c\n",table[key(s)]);
    }
    return 0;
}
