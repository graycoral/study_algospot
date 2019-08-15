#include <stdio.h>
#define MAXN	((int)2e5+10)

int N, M;
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
	static int retVal = -1;

	if (s > e)	return retVal;

	if (q[m] == val) {
		int tmp = -1;
		retVal = m;
		tmp = downBS(s, m - 1, val);
		if (tmp != -1)	retVal = tmp;
	}
	else if (q[m] > val) { return upBS(s, m - 1, val); }
	else { return upBS(m + 1, e, val); }

	return retVal;
}

int upBS(int s, int e, int val)
{
	int m = (s + e) / 2;
	static int retVal = -1;

	if (s > e )	return retVal;

	if (q[m] == val) {
		int tmp = -1;
		retVal = m;
		tmp = upBS(m + 1, e, val);
		if (tmp != -1)	retVal = tmp;
	}
	else if (q[m] > val) { return upBS(s, m - 1, val); }
	else { return upBS(m + 1, e, val); }

	return retVal;
}

void sol()
{
	int retVal = -1;
	int M;
	scanf("%d", &M);

	while (M--) {
		int tmp, hi=0, low=0;
		scanf("%d", &tmp);

		hi = upBS(0, N - 1, tmp);
		low = downBS(0, N - 1, tmp);
		retVal = hi - low + 1;

		if (low < 0) retVal = 0;
		printf("%d ", retVal);
	}
}

int main()
{
	input();
	sol();

	return 0;
}