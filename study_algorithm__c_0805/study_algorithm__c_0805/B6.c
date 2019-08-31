#include <stdio.h>
#define MAXN	((int)100+10)

int N;
char map[MAXN][MAXN];
int v[MAXN][MAXN];
int ansA =1, ansB =1;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
}

int DFS(int r, int c, char val, int cnt) {
	if (r >= N || r < 0 || c >= N || c < 0) return;
	if (v[r][c] > 0)	return;
	if (val != map[r][c]) {	return;}

	v[r][c] = cnt;

	for (int i = 0; i < 4; i++) {
		DFS(r + dr[i], c + dc[i], map[r][c], cnt);
	}
}

int sol()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DFS(i, j, map[0][0]);
		}
	}
}

void print()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%3d ", v[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	input();
	sol();
	printf("%d %d\n", ansA, ansB);
	print();
	return 0;
}