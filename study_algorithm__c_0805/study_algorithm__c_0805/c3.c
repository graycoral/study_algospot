#include <stdio.h>
#define MAXN	((int)10 +2)

int N, W;
int coin[MAXN];
int CNT;

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
	int m, n;

	for (int i = N - 1; i >= 0; i--) {
		
	}

}

int main()
{
	input();
	return 0;
}