#include <stdio.h>
#define MAXN    ((int)20+2)
int N;
int map[MAXN][MAXN];
int CNT = 0xffff;
int CNT1 = 0xffff;
int used[MAXN];
int data[MAXN];
int path[MAXN], path2[MAXN];

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
		if (tmpSum < CNT) {
			CNT = tmpSum;
			for (int i = 0; i < N; i++) {
				path2[i] = path[i];
			}
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		path[idx] = i +1;
		data[idx] = map[idx][i];
		DFS3(idx + 1);
		used[i] = 0;
	}
}

void DFS4(int idx, int sum)
{
	if (idx >= N) {
		CNT = sum;
		for (int i = 0; i < N; i++) {
			path2[i] = path[i];
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == 1)	continue;
		if (sum + map[idx][i] >= CNT)	continue;
		used[i] = 1;
		path[i] = idx + 1;
		DFS4(idx + 1, sum + map[idx][i]);
		used[i] = 0;
	}
}

int main()
{
	input();
	DFS4(0, 0);
	printf("%d\n", CNT);
	for (int i = 0; i < N; i++) {
		printf("%d ", path2[i]);
	}
	return 0;
}