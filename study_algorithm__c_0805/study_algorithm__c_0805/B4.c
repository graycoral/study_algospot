#include <stdio.h>
#define MAXN	((int)1e4+10)
#define IFN		(0xffff)

int dist[MAXN][MAXN];
int N;
int v[MAXN];
int wp, rp;
int q[MAXN*MAXN];

#if 1
void input()
{
	int i, P, d;
	char s, e;
	
	scanf("%d", &P);
	for (i = 0; i < P; i++) {
		scanf(" %c %c %d", &s, &e, &d);
		if ((dist[s][e] == 0) || (dist[s][e] > d)) {
			dist[s][e] = dist[e][s] = d;
		}
	}

	for (int i = 'A'; i <= 'z'; i++) {
		v[i] = IFN;
	}
}
#else
void input()
{
	int i, P, d;
	char s, e;
	scanf("%d", &P);
	for (i = 0; i < P; i++) {
		scanf(" %c %c %d", &s, &e, &d);
		if ((dist[s][e] == 0) || (dist[s][e] > d)) {//도로가 여러개 일수있으므로
			dist[s][e] = dist[e][s] = d;//양방향 도로
		}
	}
	for (int i = 'A'; i <= 'z'; i++) {
		v[i] = IFN;
	}
}
#endif

void push(int n, int t) {
	if (v[n] < t)	return;
	v[n] = t;
	q[wp++] = n;
}

int pop() {
	return q[rp++];
}

int empty() { return wp == rp; }

int BFS()
{
	int retVal = 'A';

	push('Z', 0);
	while (!empty()) {
		int cur = pop();
		for (int i = 'A'; i <= 'z'; i++) {
			if (dist[cur][i] == 0)	continue;
			push(i, v[cur]+dist[cur][i]);
		}
	}
	for (int i = 'A'; i < 'Z'; i++) {
		if (v[retVal] > v[i]) retVal = i;
	}
	return retVal;
}

int main()
{
	int ans = -1;
	input();
	ans = BFS();
	printf("%c %d", ans, v[ans]);
	return 0;
}