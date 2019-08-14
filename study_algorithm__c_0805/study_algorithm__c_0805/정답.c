//기출문제 : 건물옥상정원 
#include <stdio.h> 
int N;//건물 수
int H[80010];//건물 높이
int stack[80010];
int sp;
void push(int data) { stack[++sp] = data; }
int top(void) { return stack[sp]; }
void pop(void) { sp--; }
int size(void) { return sp; }
int empty(void) { return sp == 0; }
void Input_Data(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}
}
long long solve(void) {
	int i;
	long long sum = 0;
	for (i = 0; i < N; i++) {
		while (!empty() && top() <= H[i]) pop();//현재 건물보다 낮거나 같은경우 제거
		sum += size();//i번째 건물을 볼수 있는 건물 수
		push(H[i]);//현재 가장 앞 건물이므로 저장
	}
	return sum;
}
int main(void) {
	long long ans = -1;
	Input_Data(); // 입력 함수
	// 코드를 작성하세요
	ans = solve();
	printf("%lld\n", ans); // 정답 출력
	return 0;
}
//A4 : 프린터 큐 
#include <stdio.h> 
#define MAXQ (100 * 100 + 10)
int N, M;//문서수, 원하는 문서 번호
struct Q {
	int n, p;//문서 번호, 우선 순위
};
struct Q queue[MAXQ];
int wp, rp;
int priocnt[10];//우선순위별 개수
void push(int n, int p) {
	queue[wp].n = n; queue[wp].p = p; wp++;
}
struct Q front(void) {
	return queue[rp];
}
void pop(void) {
	rp++;
}
int size(void) {
	return wp - rp;
}
int empty(void) {
	return wp == rp;
}
void Initial(void) {
	int i;
	wp = rp = 0;//큐 초기화
	for (i = 1; i <= 9; i++) priocnt[i] = 0;//배열 초기화
}
void InputData(void) {
	int i, p;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &p);
		priocnt[p]++;//각 우선순위 개수 파악
		push(i, p);
	}
}
int solve(void) {
	int i, seq = 0;
	for (i = 9; i >= 1; i--) {
		while (priocnt[i]) {
			if (front().p != i) {//낮은 우선순위 문서임
				push(front().n, front().p);//뒤로 보내기
			}
			else {//출력할 우선 순위 문서임
				seq++;
				priocnt[i]--;
				if (front().n == M) return seq;//끝
			}
			pop();
		}
	}
	return -1;//이런 경우 없음(디버깅을 위해)
}
int main() {
	int T, ans;
	scanf("%d", &T);
	while (T--) {
		Initial();
		InputData();
		ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
//기출문제 : 장기자랑
#include <stdio.h>
#define MAXQ ((int)1e4 + 10)
int N;//직원 수
int S;//시작 직원 번호
int M;
int queue[MAXQ];
int wp, rp, cnt;
void push(int data) {
	queue[wp] = data;
	cnt++;
	if (++wp >= MAXQ) wp = 0;
}
int front(void) { return queue[rp]; }
void pop(void) {
	cnt--;
	if (++rp >= MAXQ) rp = 0;
}
int size(void) { return cnt; }
int empty(void) { return cnt == 0; }
void InputData() {
	scanf("%d %d %d", &N, &S, &M);
}
void solve(void) {
	int i, j;
	wp = rp = cnt = 0;//큐 초기화
	for (i = 0; i < N; i++) {
		push(S);
		if (++S > N) S = 1;
	}
	for (i = 1; i < N; i++) {//N-1회 반복
		for (j = 1; j < M; j++) {//M-1회 반복
			push(front()); pop();
		}
		printf("%d ", front()); pop();
	}
	printf("%d ", front());//N번째
}
int main() {
	InputData();// 입력 함수
	// 코드를 작성하세요
	solve();
	return 0;
}
//A5 : 모범생(단순정렬 이용)
#include <stdio.h>
#define MAXN ((int)3e4 + 10)
int N;
struct DATA {
	int id, score;
};
struct DATA A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i].score);
		A[i].id = i + 1;
	}
}
void OutputData(void) {
	int i;
	for (i = 0; i <= 2; i++) {
		printf("%d ", A[i].id);
	}
}
int comp(struct DATA* a, struct DATA* b) {//a가 좋으면 양수, 같으면 0, b가 좋으면 음수
	if (a->score == b->score) return b->id - a->id;
	return a->score - b->score;
}
void solve(void) {
	int i, j;
	struct DATA tmp;
	for (i = 0; i < 3; i++) {
		for (j = i + 1; j < N; j++) {
			//            if((A[i].score < A[j].score) ||
			//               ((A[i].score == A[j].score) && (A[i].id > A[j].id))){
			if (comp(&A[i], &A[j]) < 0) {
				tmp = A[i]; A[i] = A[j]; A[j] = tmp;
			}
		}
	}
}
int main() {
	InputData();
	solve();
	OutputData();
	return 0;
}
//A5 : 모범생(qsort 이용)
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)3e4 + 10)
int N;
struct DATA {
	int id, score;
};
struct DATA A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i].score);
		A[i].id = i + 1;
	}
}
void OutputData(void) {
	int i;
	for (i = 0; i <= 2; i++) {
		printf("%d ", A[i].id);
	}
}
//오름차순인 경우 a가 좋으면 양수, b가 좋으면 음수, 같으면 0을 리턴
//내림차순인 경우 a가 좋으면 음수, b가 좋으면 양수, 같으면 0을 리턴
int comp(const void* a, const void* b) {//내림차순
	struct DATA* x = a, * y = b;
	if (x->score == y->score) return x->id - y->id;
	return y->score - x->score;
}
int main() {
	InputData();
	qsort(A, N, sizeof(A[0]), comp);
	OutputData();
	return 0;
}
//A6 : 숫자찾기(이진탐색)
#include <stdio.h>
#define MAXN ((int)5e4 + 10)
#define MAXT ((int)1e4 + 10)
int N;
int A[MAXN];
int T;
int B[MAXT];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d", &B[i]);
	}
}
#if 0
int binarysearch(int s, int e, int d) {
	int m;
	while (s <= e) {
		m = (s + e) / 2;
		if (A[m] == d) return m;//찾기 성공
		if (A[m] > d) e = m - 1;
		else s = m + 1;
	}
	return 0;//찾기 실패
}
#else
int binarysearch(int s, int e, int d) {
	int m = (s + e) / 2;
	if (s > e) return 0;//찾기 실패
	if (A[m] == d) return m;//찾기 성공
	if (A[m] > d) return binarysearch(s, m - 1, d);
	return binarysearch(m + 1, e, d);
}
#endif // 1
void solve(void) {
	int i, idx;
	for (i = 1; i <= T; i++) {
		idx = binarysearch(1, N, B[i]);
		printf("%d\n", idx);
	}
}
int main() {
	InputData();
	solve();
	return 0;
}
//A7 : 숫자 카운팅
#include <stdio.h>
#define MAXN ((int)2e5 + 10)
int N;
int A[MAXN];
int M;
int B[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
}
int bslowerbound(int s, int e, int d) {
	int m, sol = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (A[m] == d) {
			sol = m; e = m - 1;
		}
		else if (A[m] > d) e = m - 1;
		else s = m + 1;
	}
	return sol;
}
int bsupperbound(int s, int e, int d) {
	int m, sol = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (A[m] == d) {
			sol = m; s = m + 1;
		}
		else if (A[m] > d) e = m - 1;
		else s = m + 1;
	}
	return sol;
}
void solve(void) {
	int i, low, hi;
	for (i = 0; i < M; i++) {
		low = bslowerbound(0, N - 1, B[i]);
		if (low < 0) {//없음
			printf("0 ");
			continue;
		}
		hi = bsupperbound(0, N - 1, B[i]);
		printf("%d ", hi - low + 1);
	}
}
int main() {
	InputData();
	solve();
	return 0;
}
//A8 : 도약(O(N^3))
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e3 + 10)
int N;
int A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int solve(void) {
	int i, j, k, cnt = 0, first, second;
	qsort(A, N, sizeof(A[0]), comp);
	for (i = 0; i < N - 2; i++) {//첫 번째 연잎
		for (j = i + 1; j < N - 1; j++) {//두 번째 연잎
			first = A[j] - A[i];//첫 번째 뛴 거리
			for (k = j + 1; k < N; k++) {//세 번째 연잎
				second = A[k] - A[j];//두 번째 뛴 거리
#if 0
				if ((first <= second) && (second <= 2 * first)) cnt++;
#else
				if (first > second) continue;
				if (2 * first < second) break;
				cnt++;
#endif
			}
		}
	}
	return cnt;
}
int main() {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//A8 : 도약(O(N^2 logN))
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)1e3 + 10)
int N;
int A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int bslow(int s, int e, int d) {//d보다 크거나 같은 값 중에 제일 작은 인덱스 찾기
	int m, sol = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (A[m] >= d) {
			sol = m; e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return sol;
}
int bsup(int s, int e, int d) {//d보다 작거나 같은 값 중에 제일 큰 인덱스 찾기
	int m, sol = -1;
	while (s <= e) {
		m = (s + e) / 2;
		if (A[m] <= d) {
			sol = m; s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return sol;
}
int solve(void) {
	int i, j, k, cnt = 0, first, low, hi;
	qsort(A, N, sizeof(A[0]), comp);
	for (i = 0; i < N - 2; i++) {//첫 번째 연잎
		for (j = i + 1; j < N - 1; j++) {//두 번째 연잎
			first = A[j] - A[i];//첫 번째 뛴 거리
			low = bslow(0, N - 1, A[j] + first);
			if (low < 0) break;
			hi = bsup(0, N - 1, A[j] + 2 * first);
			cnt += hi - low + 1;
		}
	}
	return cnt;
}
int main() {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//A9 : 최소 비용으로 포장 다시 하기(퀵정렬 활용)
#include <stdio.h>
#include <stdlib.h>
#define MAXN ((int)5e3 + 10)
int N;
int A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}
int comp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}
int solve(void) {
	int i, sum = 0;
	for (i = 0; i < N - 1; i++) {
		qsort(&A[i], N - i, sizeof(A[0]), comp);//i번째 부터 오름차순 정렬
		A[i + 1] += A[i];//제일 작은 두개 합치기
		sum += A[i + 1];//그 비용 누적 계산
	}
	return sum;
}
int main() {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
//A9 : 최소 비용으로 포장 다시 하기(단순정렬 활용)
#include <stdio.h>
#define MAXN ((int)5e3 + 10)
int N;
int A[MAXN];
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}
void sort(int s, int e) {//제일 작은 값 두개만 찾기
	int i, j, tmp;
	for (i = s; i < s + 2; i++) {
		for (j = i + 1; j <= e; j++) {
			if (A[i] > A[j]) {
				tmp = A[i]; A[i] = A[j]; A[j] = tmp;
			}
		}
	}
}
int solve(void) {
	int i, sum = 0;
	for (i = 0; i < N - 1; i++) {
		sort(i, N - 1);//i번째 부터 오름차순 정렬
		A[i + 1] += A[i];//제일 작은 두개 합치기
		sum += A[i + 1];//그 비용 누적 계산
	}
	return sum;
}
int main() {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}