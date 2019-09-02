//B3 : 지하철(BFS)
#include <stdio.h>
#define MAXN (100 + 10)
#define INF (100 * 100 + 10)
int N;//지하철역수
int M;//목적역
int time[MAXN][MAXN];//걸리는 시간
int visited[MAXN];//경험표시(출발역에 걸리는 시간을 저장, 중복방문때 활용)
int path[MAXN];//경로 저장(이전 역을 저장하면 됨)
int queue[MAXN * 50];//크기는 경험개수(visited배열 크기 * 50) linear queue
//적게는 10배, 많게는 100배 정도 필요(공간복잡도 문제시 circular queye 사용)
int wp, rp;
void push(int n, int t, int pre) {
	if (visited[n] <= t) return;//이전이 더 좋았음
	visited[n] = t;//방문표시(경험표시)
	path[n] = pre;//이전 역 번호 저장
	queue[wp++] = n;
}
int front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData(void) {
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {//세로 인덱스
		for (j = 1; j <= N; j++) {//가로 인덱스
			scanf("%d", &time[i][j]);
		}
	}
}
int BFS(void) {
	int cur, e;
	wp = rp = 0;//1.필요시 초기화
	for (e = 1; e <= N; e++) {
		visited[e] = INF;//좋을 때만 확산하기 위해 큰 값으로 초기화
		path[e] = 0;
	}
	push(1, 0, 0); //2.초기위치 큐에 저장
	while (!empty()) {//3.반복문
		cur = front(); pop();
		for (e = 1; e <= N; e++) {//N방향
			push(e, visited[cur] + time[cur][e], cur);
		}
	}
	//if (visited[M] == INF) 인 경우 도착 실패(이 문제는 이런 경우 없음)
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