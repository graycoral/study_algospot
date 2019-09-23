#include <stdio.h>
#define MAXN	((int)10e5+10)
#define MAXW	((int)10e9+10)

int data[MAXN];
int N,W;
int solN = 0;

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &W);
}

int check(int num)
{
	int sum = W;
	for (int i = 0; i < N; i++) {
		if (data[i] > num)	{ sum -= num; }
		else				{ sum -= data[i]; }

		if (sum < 0) return -1;
	}

	return 1;
}


void BS(int s, int e)
{

	int num = (s + e) / 2;

	if (num <= solN)	return;
	if (s > e)	return;

	if (check(num) == 1) { solN = num; BS(num + 1, e);	}
	else				 { BS(s, num - 1);	}
}

void sol()
{
	int maxnN = 0;

	for (int i = 0; i < N; i++) {
		if (maxnN < data[i])	maxnN = data[i];
	}
	BS(0, maxnN);
}

int main()
{
	input();
	sol();
	printf("%d", solN);
	return 0;
}