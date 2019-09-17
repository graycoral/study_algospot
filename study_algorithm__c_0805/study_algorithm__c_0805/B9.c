#include <stdio.h>

#define MAXN	((int) 20 + 2)

int N, CNT=0, CNT1 = 0;
int data[MAXN];
int used[MAXN];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}
}
/*
int check(int sum, int data)
{
	int retVal = 1;
	int div = 10;

	while (sum && data) {
		if ((sum % div) + (data % div) > 10) return -1;
		else {
			sum /= 10;
			data /= 10;
		}
	}
	
	return retVal;
}
*/

int check(int sum, int w) {
	while (sum && w) {
		if (sum % 10 + w % 10 >= 10) return 0;//올림 발생(태울수없음)
		sum /= 10;
		w /= 10;
	}
	return 1;//가능
}

void DFS(int idx, int sum) {
	if (CNT1 >= CNT + N - idx)	return;
	if (CNT1 < CNT) CNT1 = CNT;

	for (int i = idx; i < N; i++) {
		if (used[idx] == 1)	continue;
		if (check(sum, data[i]) == 0)	continue;
		used[idx] = 1;
		CNT++;
		DFS(idx + 1, sum + data[i]);
		CNT = 0;
		used[idx] = 0;
	}
}

void DFS1(int idx, int sum, int cnt)
{
	//if (CNT1 >= cnt + N - idx)	return;
	if (CNT1 < cnt)	CNT1 = cnt;

	for (int i = idx; i < N; i++) {
		if (check(sum, data[i]) == 0)	continue;
		DFS1(i+1, sum + data[i], cnt + 1);
	}
}

int main()
{
	input();
	//DFS1(0, 0, 0);
	DFS(0, 0);
	printf("%d", CNT1);
	return 0;
}