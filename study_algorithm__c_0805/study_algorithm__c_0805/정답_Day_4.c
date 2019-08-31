//���⹮�� : ����â��
#include <stdio.h>
#define MAXN (100 + 10)
#define INF (100 * 100 + 10)
int N, M;//���� ��, ���� ���� ��
int A[5000], B[5000], D[5000];//���� A, ���� B, �Ÿ� D
int dist[MAXN][MAXN];//���尣 �Ÿ�
int visited[MAXN];
int queue[MAXN * 50];
int wp, rp;
void push(int n, int t) {
	if (visited[n] <= t) return;//������ �� ������
	visited[n] = t;//�湮ǥ��(����ǥ��)
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
	wp = rp = 0;//1.�ʱ�ȭ
	for (e = 1; e <= N; e++) {
		visited[e] = INF;
	}
	push(start, 0);//2.������ġ ť�� ����
	while (!empty()) {//3.�ݺ���
		cur = front(); pop();
		for (e = 1; e <= N; e++) {
			if (dist[cur][e] == 0) continue;//��� ����
			push(e, visited[cur] + dist[cur][e]);
		}
	}
	for (e = 2; e <= N; e++) {
		if (visited[idx] < visited[e]) idx = e;
	}
	return visited[idx];//4.�������
}
int solve(void) {
	int i, ret, mindist = INF;
	//���尣 �Ÿ� �迭�� ����
	for (i = 0; i < M; i++) {
		dist[A[i]][B[i]] = D[i];//����� ����
		dist[B[i]][A[i]] = D[i];
	}
	for (i = 1; i <= N; i++) {//�� ���忡�� ���
		ret = BFS(i);
		if (mindist > ret) mindist = ret;
	}
	return mindist;
}
int main(void) {
	int ans = -1;
	InputData(); // �Է� �Լ�
	ans = solve();
	printf("%d\n", ans); // ���� ���
	return 0;
}

//B4 : �Ͱ� 
#include <stdio.h>
#define MAXN (128)
#define INF (1000 * 100 + 10)
int dist[MAXN][MAXN];//���尣�� �Ÿ�
int visited[MAXN];
int queue[MAXN * 50];
int wp, rp;
void push(int n, int t) {
	if (visited[n] <= t) return;//������ �� ������
	visited[n] = t;//�湮ǥ��(����ǥ��)
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
		if ((dist[s][e] == 0) || (dist[s][e] > d)) {//���ΰ� ������ �ϼ������Ƿ�
			dist[s][e] = dist[e][s] = d;//����� ����
		}
	}
}
int BFS(void) {
	int cur, idx = 'A', e;
	wp = rp = 0;//1.�ʱ�ȭ
	for (e = 'A'; e <= 'z'; e++) {
		visited[e] = INF;
	}
	push('Z', 0);//2.������ġ ť�� ����
	while (!empty()) {//3.�ݺ���
		cur = front(); pop();
		for (e = 'A'; e <= 'z'; e++) {
			if (dist[cur][e] == 0) continue;//��� ����
			push(e, visited[cur] + dist[cur][e]);
		}
	}
	for (e = 'B'; e < 'Z'; e++) {
		if (visited[idx] > visited[e]) idx = e;
	}
	return idx;//4.�������
}
int main(void) {
	int ans = -1;
	InputData(); // �Է� �Լ�
	ans = BFS();
	printf("%c %d\n", ans, visited[ans]); // ���� ���
	return 0;
}
//B5 : ������ȣ���̱�(Flood Fill)
#include <stdio.h>
#include <stdlib.h>
#define MAXN (25 + 5)
int N;
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int house;
int sol[MAXN * MAXN];
int dr[] = { -1, 1,  0, 0 };//�����¿�
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
//B6 : �̼�������ȸ(Flood Fill)
#include <stdio.h>
#define MAXN (100 + 10)
int N;
char map[MAXN][MAXN];
int visited[MAXN][MAXN];
int dr[] = { -1, 1,  0, 0 };//�����¿�
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
	//1.�Ϲ� �ܲ���
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (visited[i][j] == 0) {
				FloodFill(i, j, map[i][j]);
				sola++;
			}
		}
	}
	//2. ���ϻ��� �ܲ���
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
//B7 : �ֻ���������1(DFS)
#include <stdio.h>
int N, M;
int num[5];
int used[7];
void DFS1(int n) {//�ߺ�����
	int i;
	if (n >= N) {//��������
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
void DFS2(int n, int s) {//�ߺ�����
	int i;
	if (n >= N) {//��������
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
void DFS3(int n) {//����
	int i;
	if (n >= N) {//��������
		for (i = 0; i < N; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1; i <= 6; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;//������� ǥ��
		num[n] = i;
		DFS3(n + 1);
		used[i] = 0;//ǥ�� ����
	}
}
int main(void) {
	scanf("%d %d", &N, &M);
	if (M == 1) {//�ߺ�����
		DFS1(0);
	}
	else if (M == 2) {//�ߺ�����
		DFS2(0, 1);
	}
	else {//����
		DFS3(0);
	}
	return 0;
}
//B8 : �ǹ������
#include <stdio.h>
#define MAXN (10 + 10)
#define INF (100 * 10 + 10)
int N;
int cost[MAXN][MAXN];//[�ǹ�][���]
int used[MAXN];//��� ��� ����
int sol;
void InputData(void) {
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {//�ǹ� �ε���
		for (j = 1; j <= N; j++) {//��� �ε���
			scanf("%d", &cost[i][j]);
		}
	}
}
void DFS(int n, int sum) {//���� �ǹ� ��ȣ, �Ѻ��
	int i;
	if (sol <= sum) return;//����ġ��(�߰����� �̹� ���� �亸�� ���������Ƿ�)
	if (n > N) {//���� ����
		sol = sum;
		return;
	}
	for (i = 1; i <= N; i++) {//���
		if (used[i] == 1) continue;//�ش� ��� �̹� ��� ��
		used[i] = 1;//��� ��� ǥ��
		DFS(n + 1, sum + cost[n][i]);//���� �ǹ���ȣ, ���ݱ������+n���ǹ���i��ҿ����ﶧ ��� ���
		used[i] = 0;//ǥ�� ����
	}
}
int solve(void) {
	sol = INF;
	DFS(1, 0);//���� �ǹ� ��ȣ, �Ѻ��
	return sol;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//B9 : ����Ż��
#include <stdio.h>
#define MAXN (20 + 10)
int N;//������
int W[MAXN];//�ҹ���
int sol;//�¿� �ִ� ������
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &W[i]);
	}
}
int check(int sum, int w) {
	while (sum && w) {
		if (sum % 10 + w % 10 >= 10) return 0;//�ø� �߻�(�¿������)
		sum /= 10;
		w /= 10;
	}
	return 1;//����
}
void DFS(int s, int sum, int cnt) {
	int i;
	if (sol >= cnt + N - s) return;//���� �Ҹ� ��� �¿��� �������� ������(����ġ��)
	if (sol < cnt) sol = cnt;
	for (i = s; i < N; i++) {
		if (check(sum, W[i]) == 0) continue;//�ø� �߻�, �¿������
		DFS(i + 1, sum + W[i], cnt + 1);
	}
}
int solve(void) {
	sol = 0;
	DFS(0, 0, 0);//�ҽ����ε���, �¿�ҹ�����, �¿�Ҹ�����
	return sol;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//���⹮�� : �������
#include <stdio.h>
int N;//��ǰ ��
int M;//��ǰ ���� ��
int ID[100000 + 10];//��ǰ ID
int idcnt[10];//�� ��ǰ�� �Ѱ���
int presum[10][100000 + 10];//�� ��ǰ�� ������
int sol;//�ּ��̵�Ƚ��
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
	if (sol <= sum) return;//����ġ��
	if (idx > M) {//��������
		sol = sum;
		return;
	}
	for (i = 1; i <= M; i++) {//��ǰ id
		if (used[i] == 1) continue;//�����
		used[i] = 1;//���ǥ��
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
		used[i] = 0;//ǥ������
	}
}
int solve(void) {
	int i, j, id;
	for (i = 1; i <= N; i++) {//��ǰ�ڸ�
		id = ID[i];
		idcnt[id]++;
		presum[id][i] = 1;
	}
	for (i = 1; i <= M; i++) {//��ǰID
		for (j = 1; j <= N; j++) {//��ǰ�ڸ�
			presum[i][j] += presum[i][j - 1];
		}
	}
	sol = N;//��� ��ǰ�� �ű�°� �־�
	DFS(1, 1, 0);//�ε���, ��ǰ���������ڸ�, �ű���ǰ��
	return sol;
}
int main() {
	int ans = -1;
	InputData();//�Է� �Լ�
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
