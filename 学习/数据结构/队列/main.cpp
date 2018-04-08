#include<stdio.h>
#include"myqueue.cpp"

int main()
{
	push(123);
	push(321);
	push(231);
	while(!isEmpty())
	{
		printf("%d\n",top());
		pop();
	}
	return 0;
}
