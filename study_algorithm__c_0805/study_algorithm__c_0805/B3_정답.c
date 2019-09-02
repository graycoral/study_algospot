//B3 : ����ö(BFS)
#include <stdio.h>
#define MAXN (100 + 10)
#define INF (100 * 100 + 10)
int N;//����ö����
int M;//������
int time[MAXN][MAXN];//�ɸ��� �ð�
int visited[MAXN];//����ǥ��(��߿��� �ɸ��� �ð��� ����, �ߺ��湮�� Ȱ��)
int path[MAXN];//��� ����(���� ���� �����ϸ� ��)
int queue[MAXN * 50];//ũ��� ���谳��(visited�迭 ũ�� * 50) linear queue
//���Դ� 10��, ���Դ� 100�� ���� �ʿ�(�������⵵ ������ circular queye ���)
int wp, rp;
void push(int n, int t, int pre) {
	if (visited[n] <= t) return;//������ �� ������
	visited[n] = t;//�湮ǥ��(����ǥ��)
	path[n] = pre;//���� �� ��ȣ ����
	queue[wp++] = n;
}
int front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData(void) {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {//���� �ε���
		for (j = 1; j <= N; j++) {//���� �ε���
			scanf("%d", &time[i][j]);
		}
	}
}
int BFS(void) {
	int cur, e;
	wp = rp = 0;//1.�ʿ�� �ʱ�ȭ
	for (e = 1; e <= N; e++) {
		visited[e] = INF;//���� ���� Ȯ���ϱ� ���� ū ������ �ʱ�ȭ
		path[e] = 0;
	}
	push(1, 0, 0); //2.�ʱ���ġ ť�� ����
	while (!empty()) {//3.�ݺ���
		cur = front(); pop();
		for (e = 1; e <= N; e++) {//N����
			push(e, visited[cur] + time[cur][e], cur);
		}
	}
	//if (visited[M] == INF) �� ��� ���� ����(�� ������ �̷� ��� ����)
	return visited[M];
}
void PRT(int m) {
	if (m == 0) return;
	PRT(path[m]);
	printf("%d ", m);
}
int main(void) {
	int ans;
	InputData();
	ans = BFS();
	printf("%d\n", ans);
	PRT(M);
	return 0;
}