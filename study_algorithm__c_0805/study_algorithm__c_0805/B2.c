#include <stdio.h>
#define MAXN ((int)100 + 10)
int N, M;
int sx, sy;
int map[MAXN][MAXN];
int v[MAXN][MAXN];
int cnt, tCnt, dCnt;

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

void input()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		char tmp[MAXN];
		scanf("%s", &tmp);
		for (int j = N - 1; j >= 0; j--) {
			map[i][j] = tmp[j] - '0';
			if (map[i][j] == 1)	tCnt++;
		}
	}
	scanf("%d %d", &sx, &sy);
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

int wp, rp;
struct point {
	int r, c, t;
};

struct point Q[MAXN];

int emppty() { return wp == rp; }
void push(int r, int c, int t) {
	if (r > M || c > N || r < 0 || c < 0)	return;
	if ((v[r][c] > 0) || (map[r][c] != 1))	return;

	v[r][c] = t;
	Q[wp].r = r; Q[wp].c = c; Q[wp++].t = t;
	cnt = t;
	dCnt++; // 감염된 아이들
	tCnt--;
}

struct point pop() { return Q[rp++]; }

int BFS(int r, int c, int cnt)
{
	struct point cur = { 0, };
	push(r, c, cnt);
	while (!emppty()) {
		cur = pop();
		for (int i = 0; i < 4; i++) {
			push(cur.r + dr[i], cur.c + dc[i], cur.t + 1);
		}
	}

	return cur.t;
}

int main()
{
	input();
	int ans = BFS(sy - 1, sx - 1, 3);
	printf("%d\n", ans);
	//printf("%d\n", tCnt - dCnt);
	printf("%d\n", tCnt);

	//print();
	return 0;
}