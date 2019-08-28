#include <stdio.h>
#include <string.h>
#define MAXN ((int)100 +10)

int X, Y;
int rp, wp;
struct pos {
	int x;
	int y;
};

int map[MAXN][MAXN];
struct pos s;
struct pos e;
struct pos q[MAXN * MAXN];

int cnt;
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

void print()
{
	for (int i = 0; i <= Y; i++) {
		for (int j = 0; j <= X; j++) {
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}
}

void input()
{	
	scanf("%d %d", &X, &Y);
	//memset(&map, 1, sizeof(int) * X * Y);
	//print();
	scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);

	for (int i = 1; i <= Y; i++) {
		char tmp[MAXN];
		scanf("%s", &tmp);
		for (int j = X; j > 0; j--) {
			map[i][j] = tmp[j - 1] - '0';
		}
	}
	//print();
}

struct pos pop()
{	
	return q[rp++];
}

void push(int x, int y, int cnt)
{
	if (x < 1 || x > X || y < 1 || y > Y)	return;
	
	q[wp].x = x;
	q[wp++].y = y;
	map[x][y] = cnt;
	printf("push!! x: %d, y:%d\n",x,y);
	print();
}

int empty() {
	return wp == rp;
}

int size() {
	return wp - rp;
}

int BFS(int x, int y) {
	int cnt = 1;

	push(x, y, cnt++);
	while (!empty()) {
		struct pos cur = pop();		
		for (int i = 0; i < 4; i++) {
			if (cur.x + dc[i] == (e.x) && cur.y + dr[i] == (e.y)) { return cnt; }
			if (map[cur.x + dc[i]][cur.y + dr[i]] != 0)	continue;
			push(cur.x + dc[i], cur.y + dr[i], cnt);
		}
		if (size() == 1) cnt++;
	}

	return -1;
}

int main()
{
	input();
	printf("%d\n", BFS(s.x, s.y));
	//print();
	return 0;
}