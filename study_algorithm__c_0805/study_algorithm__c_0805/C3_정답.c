//C3 : ������ȯ
#include <stdio.h>
#define INF ((int)1e5)
#define MAXN (10+2)
#define MAXW ((int)64e3 + 2)
int dp[MAXW];//[�ܵ�]
//(1:DFS, 2:memoization, 3:dynamic(2�����迭), 4:dynamic(1�����迭))
int N;//���� �ܰ��
int coin[MAXN];//���� ����
int W;//�ܵ�

//i��° ������ �����ؼ� j�ܵ��� ���鶧 ���Ǵ� �ּ� ���� ��
int solve(void) {
	int i, j;
	//�ʱ�ȭ
	for (j = 1; j <= W; j++) dp[j] = INF;//���������� ���������(�Ұ���)
	dp[0] = 0;//0���� ���������(0���ʿ�)
	for (i = 1; i <= N; i++) {//���� ���� �ε���
		for (j = coin[i]; j <= W; j++) {//�ܵ� �ε���
			if (dp[j] > dp[j - coin[i]] + 1) {
				dp[j] = dp[j - coin[i]] + 1;
			}
		}
	}
	return dp[W];
}

void InputData(void) {
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}
	scanf("%d", &W);
}
int main(void) {
	int ans;
	InputData();
	ans = solve();
	if (ans == INF) printf("impossible\n");
	else printf("%d\n", ans);
	return 0;
}