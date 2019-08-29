#include <stdio.h>
#include <string.h>
#define MAXN ((int)100 +10)

/*
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, 
(1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, 
���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.

���� �Է� 1
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