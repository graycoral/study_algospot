//C5 : 예산
#include <stdio.h>
#define MAXN ((int)1e4 + 10)
int N;//지방수
int A[MAXN];//요청 예산
int M;//총예산
void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
}
int check(int m) {//상한액으로 가능한 값인지 판단
	int i, sum = M;
	for (i = 1; i <= N; i++) {
		if (A[i] < m) sum -= A[i];//상한액 보다 낮으므로 그대로 지급
		else sum -= m;//상한액보다 높으므로 상한액 지급
		if (sum < 0) return 0;//불가능
	}
	return 1;//가능
}
int solve(void) {
	int i, s = 0, e = 0, m, sol = 0;
	for (i = 1; i <= N; i++) {//요청 예산 중 최대값 찾기
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