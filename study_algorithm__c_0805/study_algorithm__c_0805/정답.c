//���⹮�� : �ǹ��������� 
#include <stdio.h> 
int N;//�ǹ� ��
int H[80010];//�ǹ� ����
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
		while (!empty() && top() <= H[i]) pop();//���� �ǹ����� ���ų� ������� ����
		sum += size();//i��° �ǹ��� ���� �ִ� �ǹ� ��
		push(H[i]);//���� ���� �� �ǹ��̹Ƿ� ����
	}
	return sum;
}
int main(void) {
	long long ans = -1;
	Input_Data(); // �Է� �Լ�
	// �ڵ带 �ۼ��ϼ���
	ans = solve();
	printf("%lld\n", ans); // ���� ���
	return 0;
}
//A4 : ������ ť 
#include <stdio.h> 
#define MAXQ (100 * 100 + 10)
int N, M;//������, ���ϴ� ���� ��ȣ
struct Q {
	int n, p;//���� ��ȣ, �켱 ����
};
struct Q queue[MAXQ];
int wp, rp;
int priocnt[10];//�켱������ ����
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
	wp = rp = 0;//ť �ʱ�ȭ
	for (i = 1; i <= 9; i++) priocnt[i] = 0;//�迭 �ʱ�ȭ
}
void InputData(void) {
	int i, p;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &p);
		priocnt[p]++;//�� �켱���� ���� �ľ�
		push(i, p);
	}
}
int solve(void) {
	int i, seq = 0;
	for (i = 9; i >= 1; i--) {
		while (priocnt[i]) {
			if (front().p != i) {//���� �켱���� ������
				push(front().n, front().p);//�ڷ� ������
			}
			else {//����� �켱 ���� ������
				seq++;
				priocnt[i]--;
				if (front().n == M) return seq;//��
			}
			pop();
		}
	}
	return -1;//�̷� ��� ����(������� ����)
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
//���⹮�� : ����ڶ�
#include <stdio.h>
#define MAXQ ((int)1e4 + 10)
int N;//���� ��
int S;//���� ���� ��ȣ
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
	wp = rp = cnt = 0;//ť �ʱ�ȭ
	for (i = 0; i < N; i++) {
		push(S);
		if (++S > N) S = 1;
	}
	for (i = 1; i < N; i++) {//N-1ȸ �ݺ�
		for (j = 1; j < M; j++) {//M-1ȸ �ݺ�
			push(front()); pop();
		}
		printf("%d ", front()); pop();
	}
	printf("%d ", front());//N��°
}
int main() {
	InputData();// �Է� �Լ�
	// �ڵ带 �ۼ��ϼ���
	solve();
	return 0;
}
//A5 : �����(�ܼ����� �̿�)
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
int comp(struct DATA* a, struct DATA* b) {//a�� ������ ���, ������ 0, b�� ������ ����
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
//A5 : �����(qsort �̿�)
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
//���������� ��� a�� ������ ���, b�� ������ ����, ������ 0�� ����
//���������� ��� a�� ������ ����, b�� ������ ���, ������ 0�� ����
int comp(const void* a, const void* b) {//��������
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
//A6 : ����ã��(����Ž��)
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
		if (A[m] == d) return m;//ã�� ����
		if (A[m] > d) e = m - 1;
		else s = m + 1;
	}
	return 0;//ã�� ����
}
#else
int binarysearch(int s, int e, int d) {
	int m = (s + e) / 2;
	if (s > e) return 0;//ã�� ����
	if (A[m] == d) return m;//ã�� ����
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
//A7 : ���� ī����
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
		if (low < 0) {//����
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
//A8 : ����(O(N^3))
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
	for (i = 0; i < N - 2; i++) {//ù ��° ����
		for (j = i + 1; j < N - 1; j++) {//�� ��° ����
			first = A[j] - A[i];//ù ��° �� �Ÿ�
			for (k = j + 1; k < N; k++) {//�� ��° ����
				second = A[k] - A[j];//�� ��° �� �Ÿ�
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
//A8 : ����(O(N^2 logN))
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
int bslow(int s, int e, int d) {//d���� ũ�ų� ���� �� �߿� ���� ���� �ε��� ã��
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
int bsup(int s, int e, int d) {//d���� �۰ų� ���� �� �߿� ���� ū �ε��� ã��
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
	for (i = 0; i < N - 2; i++) {//ù ��° ����
		for (j = i + 1; j < N - 1; j++) {//�� ��° ����
			first = A[j] - A[i];//ù ��° �� �Ÿ�
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
//A9 : �ּ� ������� ���� �ٽ� �ϱ�(������ Ȱ��)
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
		qsort(&A[i], N - i, sizeof(A[0]), comp);//i��° ���� �������� ����
		A[i + 1] += A[i];//���� ���� �ΰ� ��ġ��
		sum += A[i + 1];//�� ��� ���� ���
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
//A9 : �ּ� ������� ���� �ٽ� �ϱ�(�ܼ����� Ȱ��)
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
void sort(int s, int e) {//���� ���� �� �ΰ��� ã��
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
		sort(i, N - 1);//i��° ���� �������� ����
		A[i + 1] += A[i];//���� ���� �ΰ� ��ġ��
		sum += A[i + 1];//�� ��� ���� ���
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