#include <stdio.h>
#define MAXN	((int)100+10)

int N;
char map[MAXN][MAXN];
int v[MAXN][MAXN];
int ansA, ansB;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
}

int DFS(int r, int c, char val) {
	if (r >= N || r < 0 || c >= N || c < 0) return;
	if ((v[r][c] > 0) || (val != map[r][c]))	return;
	
	v[r][c] = ansA;

	for (int i = 0; i < 4; i++) {
		DFS(r + dr[i], c + dc[i], map[r][c]);
	}
}

int sol()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 0) ansA++;
			DFS(i, j, map[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = 0;
			if (map[i][j] == 'R')	map[i][j] = 'G';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 0) ansB++;
			DFS(i, j, map[i][j]);
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
	//print();
	return 0;
}