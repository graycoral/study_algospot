#include <stdio.h>
#define MAXN[2e5+10]

int N, M;
int q[MAXN];

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &q[i]);
	}
}

int upBS(int s, int e, int val)
{
	int m = (s + e) / 2;
	static int retVal = -1;	 

	if (s > e)	return retVal;

	if (q[m] == val) {
		retVal = m;
		upBS(s, m + 1, val);
	}
	else if (q[m] > val) { return upBS(s, m - 1, val);	}
	else { return upBS(m + 1, e, val); }
		
	return retVal;
}

int downBS(int s, int e, int val)
{
	int m = (s + e) / 2;
	static int retVal = -1;

	if (s > e)	return retVal;

	if (q[m] == val) {
		retVal = m;
		downBS(s, m - 1, val);
	}
	else if (q[m] > val) { return upBS(s, m - 1, val); }
	else { return upBS(m + 1, e, val); }

	return retVal;
}

int sol()
{
	int retVal = -1;
	int M;
	scanf("%d", &M);

	while (M--) {
		int tmp;
		scanf("%d", &tmp);
		retVal = upBS(0, N, tmp) - downBS(0, N, tmp);
	}

	return retVal;
}

int main()
{
	int ans = 0;
	
	input();
	ans = sol();
	printf("%d", ans);

	return 0;
}