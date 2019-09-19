#include <stdio.h>
#include <stdlib.h>
#define MAXN	((int)10 +2)
#define IFN		(0x7fffffff)
#define TEST (2)

int N, W;
int coin[MAXN];
int CNT = IFN;

void input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {   
		scanf("%d", &coin[i]);
	}
	scanf("%d", &W);
}

void DFS(int n, int w, int cnt)
{
	if (CNT <= cnt)	return;	

	if (w == 0) { 
		CNT = cnt;
		return;
	}

	if (n >= N)		return;

	for (int i =  w/coin[n]; i >= 0; i--) {
		DFS(n + 1, w-(i*coin[n]), cnt+i);
	}
}



void sol()
{
#if TEST == 1 // time over
	DFS(0, W, 0);
#else TEST == 2 

#endif
}

int main()
{
	input();
	

	if (CNT == IFN)	printf("impossible\n");
	else			printf("%d", CNT);
	return 0;
}