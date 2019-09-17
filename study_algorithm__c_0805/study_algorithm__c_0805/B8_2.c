#include <stdio.h>

#define MAX (20)
#define INF (0x7fffffff)

int N;
int table[MAX + 1][MAX + 1];

int sol;
int sel[MAX + 1];
int path[MAX + 1];
int sol_path[MAX + 1];

void input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &table[i][j]);
		}
	}
}

void DFS(int n, int sum) {
	int i;
	if (n > N) {
		sol = sum;
		for (int i = 1; i <= N; i++) {
			sol_path[i] = path[i];
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (sel[i] == 1)	continue;
		if (sum + table[n][i] > sol)	continue;
		sel[i] = 1; path[n] = i;
		DFS(n + 1, sum + table[n][i]);
		sel[i] = 0; path[n] = 0;
	}
}


void print()
{
	for (int i = 1; i <= N; i++) {
		printf("%d ", sol_path[i]);
	}

}

int main()
{
	input();
	sol = INF;
	DFS(1, 0);
	printf("%d\n", sol);
	print();

	return 0;
}
