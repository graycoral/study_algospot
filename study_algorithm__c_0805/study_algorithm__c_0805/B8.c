#include <stdio.h>
#define MAXN	((int)10+2)
int N;
int map[MAXN][MAXN];
int CNT = 0xffff;
int used[MAXN];
int data[MAXN];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void DFS3(int idx)
{
	int tmpSum = 0;
	if (idx >= N) {
		for (int i = 0; i < N; i++) {
			tmpSum += data[i];
		}
		if (tmpSum < CNT)	CNT = tmpSum;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		data[idx] = map[idx][i];
		DFS3(idx + 1);
		used[i] = 0;
	}
}

int main()
{
	input();
	DFS3(0);
	printf("%d", CNT);
	return 0;
}