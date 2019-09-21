//C3 : 동전교환
#include <stdio.h>
#define INF ((int)1e5)
#define MAXN (10+2)
#define MAXW ((int)64e3 + 2)
int dp[MAXW];//[잔돈]
//(1:DFS, 2:memoization, 3:dynamic(2차원배열), 4:dynamic(1차원배열))
int N;//동전 단계수
int coin[MAXN];//동전 단위
int W;//잔돈

//i번째 동전을 포함해서 j잔돈을 만들때 사용되는 최소 동전 수
int solve(void) {
	int i, j;
	//초기화
	for (j = 1; j <= W; j++) dp[j] = INF;//동전없으면 만들수없음(불가능)
	dp[0] = 0;//0원은 만들수있음(0개필요)
	for (i = 1; i <= N; i++) {//동전 단위 인덱스
		for (j = coin[i]; j <= W; j++) {//잔돈 인덱스
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