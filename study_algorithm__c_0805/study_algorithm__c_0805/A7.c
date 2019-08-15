#include <stdio.h>
#define MAXN	((int)2e5+10)

int N, M, retValUp, retValDown;
int q[MAXN];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &q[i]);
	}
}

int downBS(int s, int e, int val)
{
	int m = (s + e) / 2;

	if (s > e)	return retValDown;

	if (q[m] == val) {
		int tmp = -1;
		retValDown = m;
		tmp = downBS(s, m - 1, val);
		if (tmp != -1)	retValDown = tmp;
	}
	else if (q[m] > val) { return downBS(s, m - 1, val); }
	else { return downBS(m + 1, e, val); }

	return retValDown;
}

int upBS(int s, int e, int val)
{
	int m = (s + e) / 2;
	if (s > e )	return retValUp;

	if (q[m] == val) {
		int tmp = -1;
		retValUp = m;
		tmp = upBS(m + 1, e, val);
		if (tmp != -1)	retValUp = tmp;
	}
	else if (q[m] > val) { return upBS(s, m - 1, val); }
	else { return upBS(m + 1, e, val); }

	return retValUp;
}

void sol()
{
	int M;
	scanf("%d", &M);

	while (M--) {
		int tmp, hi=0, low=0;
		retValUp = -1; retValDown = -1;
		scanf("%d", &tmp);

		low = downBS(0, N - 1, tmp);
		if (low < 0) {
			printf("0 ");
			continue;
		}

		hi = upBS(0, N - 1, tmp);
		printf("%d ", hi - low + 1);
	}
}

int main()
{
	input();
	sol();

	return 0;
}