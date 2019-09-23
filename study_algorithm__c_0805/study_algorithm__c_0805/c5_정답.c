//C5 : ����
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int N;//�����
int A[MAXN];//��û ����
int M;//�ѿ���
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
}
int check(int m) {//���Ѿ����� ������ ������ �Ǵ�
	int i, sum = M;
	for (i = 1; i <= N; i++) {
		if (A[i] < m) sum -= A[i];//���Ѿ� ���� �����Ƿ� �״�� ����
		else sum -= m;//���Ѿ׺��� �����Ƿ� ���Ѿ� ����
		if (sum < 0) return 0;//�Ұ���
	}
	return 1;//����
}
int solve(void) {
	int i, s = 0, e = 0, m, sol = 0;
	for (i = 1; i <= N; i++) {//��û ���� �� �ִ밪 ã��
		if (e < A[i]) e = A[i];
	}
	while (s <= e) {
		m = (s + e) / 2;
		if (check(m) == 1) {
			sol = m; s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return sol;
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}