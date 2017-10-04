#include<stdio.h>
#include<string.h>

const char keys[] = "A#Bb C#Db D#Eb F#Gb G#Ab";
const char words[] = "BbA# DbC# EbD# GbF# AbG#";

int main()
{
    int T = 1;
    char s1[100],s2[100];
    while(scanf("%s%s",s1,s2) == 2)
    {
        if(strlen(s1) == 1) printf("Case %d: UNIQUE\n",T++);
        else
        {
            int i;
            for(i = 0; i < strlen(keys); i++)
                if(keys[i] == s1[0] && keys[i+1] == s1[1]) break;
            printf("Case %d: %c%c %s\n",T++,words[i],words[i+1],s2);
        }
    }
    return 0;
}
