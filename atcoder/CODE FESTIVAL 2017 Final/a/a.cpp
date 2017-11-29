#include<stdio.h>
#include<string.h>

const int maxn= 100;
char s[maxn];

int main()
{
	while(scanf("%s",s) == 1)
	{
		int ok = 0;
		if(strcmp(s,"KIHBR") == 0) ok = 1;
		if(strcmp(s,"AKIHBR") == 0) ok = 1;
		if(strcmp(s,"KIHABR") == 0) ok = 1;
		if(strcmp(s,"KIHBAR") == 0) ok = 1;
		if(strcmp(s,"KIHBRA") == 0) ok = 1;
		if(strcmp(s,"AKIHABR") == 0) ok = 1;
		if(strcmp(s,"AKIHBAR") == 0) ok = 1;
		if(strcmp(s,"AKIHBRA") == 0) ok = 1;
		if(strcmp(s,"KIHABAR") == 0) ok = 1;
		if(strcmp(s,"KIHABRA") == 0) ok = 1;
		if(strcmp(s,"KIHBARA") == 0) ok = 1;
		if(strcmp(s,"AKIHABAR") == 0) ok = 1;
		if(strcmp(s,"AKIHABRA") == 0) ok = 1;
		if(strcmp(s,"AKIHBARA") == 0) ok = 1;
		if(strcmp(s,"KIHABARA") == 0) ok = 1;
		if(strcmp(s,"AKIHABARA") == 0) ok = 1;
		
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

