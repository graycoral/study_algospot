#include <stdio.h>
#include <string.h>
#define MAXN ((int)100 +10)

/*
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, 
(1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 
서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1
4 6
101111
101010
101011
111011

*/


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
	scanf("%d %d", &Y, &X);

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
	if (map[r][c] != 1)	return;
	v[r][c] = cnt;
	q[wp].r = r; q[wp].c = c; q[wp++].t = cnt;
}

int empty() {
	return wp == rp;
}

int size() { return wp - rp; }

int BFS() {
	push(1, 1, 1);
	while (!empty()) {
		struct pos cur = pop();
		if ((cur.r == Y) && (cur.c == X)) { return cur.t; }
		for (int i = 0; i < 4; i++) {
			push(cur.r + dr[i], cur.c + dc[i], cur.t + 1);
		}
	}
	return -1;
}

int main()
{
	input();
	printf("%d\n", BFS());
	return 0;
}