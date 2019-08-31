#include <stdio.h>
#define MAXN ((int)100 + 10)
int N, M;
int sr, sc;
int map[MAXN][MAXN];
int v[MAXN][MAXN];
int cnt;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		char tmp[MAXN];
		scanf("%s", &tmp);
		for (int j = N; j > 0; j--) {
			map[i][j] = tmp[j - 1] - '0';
		}
	}
	scanf("%d %d", &sr, &sc);
}

void DFS(int r, int c, int value)
{
	if (r > N || c > M || r < 0 || c < 0)	return;
	if (v[r][c] != 0 && v[r][c] < value)	return;
	if (map[r][c] != 1)	return;

	cnt = value;
	v[r][c] = value;
	map[r][c] = value;

	for (int i = 0; i < 4; i++) {
		DFS(r + dr[i], c + dc[i], value + 1);
	}
}

int cntAlive()
{
	int retVal = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1)	retVal++;
		}
	}

	return retVal;
}

void print()
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%3d ", v[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int ans = 0;
	input();
	DFS(sr, sc, 1);
	printf("%d\n", cnt - 3);
	printf("%d\n", cntAlive());
	//print();
	return 0;
}