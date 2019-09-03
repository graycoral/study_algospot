#include <stdio.h>
#define MAXN	((int)100 +10)

int N, M;
int map[MAXN][MAXN];
int q[MAXN * MAXN];
int v[MAXN * MAXN];
int path[MAXN];
int wp, rp;

void input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; i < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

int empty()	{ return wp == rp; }
int pop()	{ return q[rp++]; }

void push(int e, int t, int pre) 
{
	if (v[e] <= t)	return;
	v[e] = t;
	path[e] = pre;
	q[wp++] = e;
}

int BFS()
{
	for (int i = 0; i < N; i++) { v[i] = 0xffff; path[i] = 0; }
	push(0, 0, 0);
	while (!empty()) {
		int cur = pop();
		for (int i = 0; i < N; i++) {
			push(i, v[cur]+map[cur][i], cur);
		}
	}

	return v[M - 1];
}

void print(int idx)
{
	if (idx == 0) {
		printf("%d ", path[idx] + 1);
		return;
	}	
	printf("%d ", path[idx] +1);
	print(path[idx]);
}

int main()
{
	int ans = 0;
	input();
	ans = BFS();
	printf("%d\n", ans);
	print(M-1);
	return 0;
}