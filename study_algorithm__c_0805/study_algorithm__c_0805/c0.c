#include <stdio.h>
#define MAXN	((int) 12 +2)

int N;
int map[MAXN][MAXN];
int SUM = 13 * 100;
int used[MAXN];
int data[MAXN];

void input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}
/*
void print()
{
	printf("==============================================\n");
	for (int i = 1; i <= N; i++) {
		printf("%d -> ", data[i]);
	}
	printf(": %d\n", SUM);
	printf("==============================================\n");
}
*/

void DFS(int s, int n, int sum)
{
	if (SUM < sum)	return;
	if (n >= N) {
		if (map[s][1] != 0) {
			sum += map[s][1];
			if (SUM > sum)	SUM = sum;
			data[n] = map[s][1];
			//print();
		}		
		return;
	}

	for (int i = 2; i <= N; i++) {
		if (map[s][i] == 0)	continue;
		if(used[i] == 1)	continue;
		used[i] = 1;
		data[n] = map[s][i];
		DFS(i, n+1, sum+map[s][i]);
		used[i] = 0;
		data[n] = 0;
	}
}

int main()
{
	input();
	DFS(1, 1, 0);
	printf("%d\n", SUM);
	return 0;
}