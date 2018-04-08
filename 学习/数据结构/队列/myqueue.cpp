
const int maxn = 100000;
int queue[maxn];
int head = 0,rear = 0;

int isEmpty()
{
	return rear == head;
}

int isFull()
{
	return (rear+1) % maxn == head;
}

int push(int e)
{
	if(isFull())
		return 0;
	queue[rear] = e;
	rear = (rear+1) % maxn;
	return 1;
}

int top()
{
	if(isEmpty())
		return 0;
	return queue[head];
}

int pop()
{
	if(isEmpty())
		return 0;
	head = (head + 1) % maxn;
	return 1;
}

