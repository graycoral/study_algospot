#include <stdio.h>
#define MAXN	((int)1e3+10)
int N;
int A[2][MAXN];
int data[100];

void input()
{
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[0][i], &A[i][i]);
	}
}

void init()
{
	memset(&data, sizeof(int), 100);
}

int check(int idx)
{
	for (int i = 0; i <= idx; i++) {

	}
}

int BS(int i, int idx, int s)
{
	if (idx > i)	return 0;
	if ()	return 1;

	data[idx] = s;
	

}

void sol(int i)
{
	int retVal = 0;
	retVal += sol(i, 0, 1);
	retVal += sol(i, 0, 0);
	
	printf("%d\n", retVal);
}

int main()
{
	input();

	for (int i = 0; i < N; i++) {
		init();
		sol();
	}
	return 0;
}