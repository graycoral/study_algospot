#include <stdio.h>
#include <string.h>
#define MAXN ((int)100 +10)

int X, Y;
int rp, wp;
struct pos {
	int r, c, t;
};

int map[MAXN][MAXN];
int v[MAXN][MAXN];
struct pos s;
struct pos e;
struct pos q[MAXN * MAXN];

int cnt;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

void input()
{
	scanf("%d %d", &X, &Y);
	scanf("%d %d %d %d", &s.c, &s.r, &e.c, &e.r);

	for (int i = 1; i <= Y; i++) {
		char tmp[MAXN];
		scanf("%s", &tmp);
		for (int j = X; j > 0; j--) {
			map[i][j] = tmp[j - 1] - '0';
		}
	}
}

struct pos pop() { return q[rp++]; }

void push(int r, int c, int cnt)
{
	if (c < 1 || c > X || r < 1 || r > Y)	return;
	if (v[r][c] > 0)	return;
	if (map[r][c] != 0)	return;
	v[r][c] = cnt;
	q[wp].r = r; q[wp].t = cnt; q[wp++].c = c;
}

int empty() {
	return wp == rp;
}

int size() { return wp - rp; }

int BFS(int r, int c) {
	push(r, c, 0);
	while (!empty()) {
		struct pos cur = pop();
		if ((cur.r == e.r) && (cur.c == e.c)) { return cur.t; }
		for (int i = 0; i < 4; i++) {
			push(cur.r + dr[i], cur.c + dc[i], cur.t + 1);
		}
	}
	return -1;
}

int main()
{
	input();
	printf("%d\n", BFS(s.r, s.c));
	return 0;
}