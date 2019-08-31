//기출문제 : 물류창고
#include <stdio.h>
#define MAXN (100 + 10)
#define INF (100 * 100 + 10)
int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
int dist[MAXN][MAXN];//공장간 거리
int visited[MAXN];
int queue[MAXN * 50];
int wp, rp;
void push(int n, int t) {
	if (visited[n] <= t) return;//이전이 더 좋았음
	visited[n] = t;//방문표시(경험표시)
	queue[wp++] = n;
}
int front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData() {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &A[i], &B[i], &D[i]);
	}
}
int BFS(int start) {
	int cur;
	int e, idx = 1;
	wp = rp = 0;//1.초기화
	for (e = 1; e <= N; e++) {
		visited[e] = INF;
	}
	push(start, 0);//2.시작위치 큐에 저장
	while (!empty()) {//3.반복문
		cur = front(); pop();
		for (e = 1; e <= N; e++) {
			if (dist[cur][e] == 0) continue;//경로 없음
			push(e, visited[cur] + dist[cur][e]);
		}
	}
	for (e = 2; e <= N; e++) {
		if (visited[idx] < visited[e]) idx = e;
	}
	return visited[idx];//4.결과리턴
}
int solve(void) {
	int i, ret, mindist = INF;
	//공장간 거리 배열로 정리
	for (i = 0; i < M; i++) {
		dist[A[i]][B[i]] = D[i];//양방향 도로
		dist[B[i]][A[i]] = D[i];
	}
	for (i = 1; i <= N; i++) {//각 공장에서 출발
		ret = BFS(i);
		if (mindist > ret) mindist = ret;
	}
	return mindist;
}
int main(void) {
	int ans = -1;
	InputData(); // 입력 함수
	ans = solve();
	printf("%d\n", ans); // 정답 출력
	return 0;
}

//B4 : 귀가 
#include <stdio.h>
#define MAXN (128)
#define INF (1000 * 100 + 10)
int dist[MAXN][MAXN];//목장간의 거리
int visited[MAXN];
int queue[MAXN * 50];
int wp, rp;
void push(int n, int t) {
	if (visited[n] <= t) return;//이전이 더 좋았음
	visited[n] = t;//방문표시(경험표시)
	queue[wp++] = n;
}
int front(void) { return queue[rp]; }
void pop(void) { rp++; }
int size(void) { return wp - rp; }
int empty(void) { return wp == rp; }
void InputData() {
	int i, P, d;
	char s, e;
	scanf("%d", &P);
	for (i = 0; i < P; i++) {
		scanf(" %c %c %d", &s, &e, &d);
		if ((dist[s][e] == 0) || (dist[s][e] > d)) {//도로가 여러개 일수있으므로
			dist[s][e] = dist[e][s] = d;//양방향 도로
		}
	}
}
int BFS(void) {
	int cur, idx = 'A', e;
	wp = rp = 0;//1.초기화
	for (e = 'A'; e <= 'z'; e++) {
		visited[e] = INF;
	}
	push('Z', 0);//2.시작위치 큐에 저장
	while (!empty()) {//3.반복문
		cur = front(); pop();
		for (e = 'A'; e <= 'z'; e++) {
			if (dist[cur][e] == 0) continue;//경로 없음
			push(e, visited[cur] + dist[cur][e]);
		}
	}
	for (e = 'B'; e < 'Z'; e++) {
		if (visited[idx] > visited[e]) idx = e;
	}
	return idx;//4.결과리턴
}
int main(void) {
	int ans = -1;
	InputData(); // 입력 함수
	ans = BFS();
	printf("%c %d\n", ans, visited[ans]); // 정답 출력
	return 0;
}
//B5 : 단지번호붙이기(Flood Fill)
#include <stdio.h>
#include <stdlib.h>
#define MAXN (25 + 5)
int N;
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int house;
int sol[MAXN * MAXN];
int dr[] = { -1, 1,  0, 0 };//상하좌우
int dc[] = { 0, 0, -1, 1 };
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", &map[i][1]);
	}
}
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
void OutputData(int cnt) {
	int i;
	qsort(sol, cnt, sizeof(sol[0]), comp);
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++) {
		printf("%d\n", sol[i]);
	}
}
void FloodFill(int r, int c) {
	int i;
	if ((map[r][c] != '1') || (visited[r][c] == 1)) return;
	visited[r][c] = 1;
	house++;
	for (i = 0; i < 4; i++) {
		FloodFill(r + dr[i], c + dc[i]);
	}
}
int solve(void) {
	int i, j, cnt = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if ((map[i][j] == '1') && (visited[i][j] == 0)) {
				house = 0;
				FloodFill(i, j);
				sol[cnt++] = house;
			}
		}
	}
	return cnt;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	OutputData(ans);
	return 0;
}
//B6 : 미술관람대회(Flood Fill)
#include <stdio.h>
#define MAXN (100 + 10)
int N;
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dr[] = { -1, 1,  0, 0 };//상하좌우
int dc[] = { 0, 0, -1, 1 };
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", &map[i][1]);
	}
}
void FloodFill(int r, int c, char color) {
	int i;
	if ((map[r][c] != color) || (visited[r][c] == 1)) return;
	visited[r][c] = 1;
	for (i = 0; i < 4; i++) {
		FloodFill(r + dr[i], c + dc[i], color);
	}
}
void solve(void) {
	int i, j, sola = 0, solb = 0;
	//1.일반 꿀꿀이
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (visited[i][j] == 0) {
				FloodFill(i, j, map[i][j]);
				sola++;
			}
		}
	}
	//2. 적록색맹 꿀꿀이
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			visited[i][j] = 0;
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (visited[i][j] == 0) {
				FloodFill(i, j, map[i][j]);
				solb++;
			}
		}
	}
	printf("%d %d\n", sola, solb);
}
int main(void) {
	InputData();
	solve();
	return 0;
}
//B7 : 주사위던지기1(DFS)
#include <stdio.h>
int N, M;
int num[5];
int used[7];
void DFS1(int n) {//중복순열
	int i;
	if (n >= N) {//종료조건
		for (i = 0; i < N; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= 6; i++) {
		num[n] = i;
		DFS1(n + 1);
	}
}
void DFS2(int n, int s) {//중복조합
	int i;
	if (n >= N) {//종료조건
		for (i = 0; i < N; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (i = s; i <= 6; i++) {
		num[n] = i;
		DFS2(n + 1, i);
	}
}
void DFS3(int n) {//순열
	int i;
	if (n >= N) {//종료조건
		for (i = 0; i < N; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= 6; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;//사용으로 표시
		num[n] = i;
		DFS3(n + 1);
		used[i] = 0;//표시 제거
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	if (M == 1) {//중복순열
		DFS1(0);
	}
	else if (M == 2) {//중복조합
		DFS2(0, 1);
	}
	else {//순열
		DFS3(0);
	}
	return 0;
}
//B8 : 건물세우기
#include <stdio.h>
#define MAXN (10 + 10)
#define INF (100 * 10 + 10)
int N;
int cost[MAXN][MAXN];//[건물][장소]
int used[MAXN];//장소 사용 여부
int sol;
void InputData(void) {
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {//건물 인덱스
		for (j = 1; j <= N; j++) {//장소 인덱스
			scanf("%d", &cost[i][j]);
		}
	}
}
void DFS(int n, int sum) {//세울 건물 번호, 총비용
	int i;
	if (sol <= sum) return;//가지치기(중간합이 이미 이전 답보다 좋지않으므로)
	if (n > N) {//종료 조건
		sol = sum;
		return;
	}
	for (i = 1; i <= N; i++) {//장소
		if (used[i] == 1) continue;//해당 장소 이미 사용 중
		used[i] = 1;//장소 사용 표시
		DFS(n + 1, sum + cost[n][i]);//다음 건물번호, 지금까지비용+n번건물을i장소에세울때 드는 비용
		used[i] = 0;//표시 제거
	}
}
int solve(void) {
	sol = INF;
	DFS(1, 0);//세울 건물 번호, 총비용
	return sol;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//B9 : 농장탈출
#include <stdio.h>
#define MAXN (20 + 10)
int N;//마리수
int W[MAXN];//소무게
int sol;//태운 최대 마리수
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &W[i]);
	}
}
int check(int sum, int w) {
	while (sum && w) {
		if (sum % 10 + w % 10 >= 10) return 0;//올림 발생(태울수없음)
		sum /= 10;
		w /= 10;
	}
	return 1;//가능
}
void DFS(int s, int sum, int cnt) {
	int i;
	if (sol >= cnt + N - s) return;//남은 소를 모두 태워도 이전보다 안좋음(가지치기)
	if (sol < cnt) sol = cnt;
	for (i = s; i < N; i++) {
		if (check(sum, W[i]) == 0) continue;//올림 발생, 태울수없음
		DFS(i + 1, sum + W[i], cnt + 1);
	}
}
int solve(void) {
	sol = 0;
	DFS(0, 0, 0);//소시작인덱스, 태운소무게합, 태운소마리수
	return sol;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//기출문제 : 재고정리
#include <stdio.h>
int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID
int idcnt[10];//각 제품별 총개수
int presum[10][100000 + 10];//각 제품의 누적합
int sol;//최소이동횟수
int used[10];
void InputData() {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &ID[i]);
	}
}
void DFS(int idx, int spos, int sum) {
	int i, npos, movecnt;
	if (sol <= sum) return;//가지치기
	if (idx > M) {//종료조건
		sol = sum;
		return;
	}
	for (i = 1; i <= M; i++) {//제품 id
		if (used[i] == 1) continue;//사용중
		used[i] = 1;//사용표시
		npos = spos + idcnt[i];
#if 01
		movecnt = idcnt[i] - (presum[i][npos - 1] - presum[i][spos - 1]);
#else
		movecnt = idcnt[i];
		for (int j = spos; j < npos; j++) {
			if (ID[j] == i) movecnt--;
		}
#endif
		DFS(idx + 1, npos, sum + movecnt);
		used[i] = 0;//표시제거
	}
}
int solve(void) {
	int i, j, id;
	for (i = 1; i <= N; i++) {//제품자리
		id = ID[i];
		idcnt[id]++;
		presum[id][i] = 1;
	}
	for (i = 1; i <= M; i++) {//제품ID
		for (j = 1; j <= N; j++) {//제품자리
			presum[i][j] += presum[i][j - 1];
		}
	}
	sol = N;//모든 제품을 옮기는게 최악
	DFS(1, 1, 0);//인덱스, 제품놓을시작자리, 옮길제품수
	return sol;
}
int main() {
	int ans = -1;
	InputData();//입력 함수
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
