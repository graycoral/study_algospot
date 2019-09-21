#include <stdio.h>
#include <stdlib.h>
#define MAXN	((int)10 +2)
#define MAXW ((int)64e3 + 2)
#define IFN		(0x7ffffff)
#define TEST (2)

int N, W;
int coin[MAXN];
int CNT = IFN;
int dp[MAXW];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {   
		scanf("%d", &coin[i]);
	}
	scanf("%d", &W);
}

void sol()
{
	dp[0] = 0;
	for (int i = 1; i <= W; i++)	dp[i] = IFN;

	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= W; j++) {
			if (dp[j] > dp[j - coin[i]] + 1) {
				dp[j] = dp[j - coin[i]] + 1;
			}
		}
	}

	CNT = dp[W];

}

int main()
{
	input();
	sol();

	if (CNT == IFN)	printf("impossible\n");
	else			printf("%d", CNT);
	return 0;
}