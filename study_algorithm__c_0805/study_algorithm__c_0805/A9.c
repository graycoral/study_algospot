#include <stdio.h>
#include <stdlib.h>

#define MAXN ((int)5e3+10)
int queue[MAXN*MAXN];
int wp, rp;


void push(int data) {
	queue[wp++] = data;
}

void pop() {
	rp++;
}

int front() {
	return queue[rp];
}

int empty() {
	return wp == rp;
}

int size() {
	return wp - rp;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int sol()
{
	int retVal = 0;

	while (size() > 1) {
		int a, b;

		qsort(&queue[0], size(), sizeof(queue[0]), compare);
		a = front(); pop();
		b = front(); pop();
		retVal += a + b;
		push(retVal);		
	}
	return retVal;
}

int main()
{
	int ans = -1;
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		push(tmp);
	}
	
	ans = sol();

	printf("%d", ans);
	return 0;
}