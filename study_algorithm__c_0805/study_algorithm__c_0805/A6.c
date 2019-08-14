#include <stdio.h>
#define MAXN ((int)5e4+10)

int N, M;
int q[MAXN];

int BS(int s, int e, int val)
{
	int retVal = -1;
	int m = (s + e) / 2;
	
	if (s > e)		return 0;
	if ((s == e) && (val != q[m])) { return 0; }

	if (val == q[m])	 { return m + 1; }
	else if (q[m] > val) { return BS(s, m-1, val); }
	else				 { return BS(m + 1, e, val); }

	return retVal;
}

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &q[i]);
	}
	scanf("%d", &M);	
}
int main()
{
	input();

	while (M--) {
		int tmpVal, ans;
		scanf("%d", &tmpVal);
		ans = BS(0, N-1, tmpVal);
		printf("%d\n", ans);
	}

	return 0;
}