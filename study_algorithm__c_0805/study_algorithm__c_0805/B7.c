#include <stdio.h>
#define MAXN	((int)10)

int N, M;
int data[7];
int used[7];

void DFS1(int idx)
{
	if (idx >= N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}	
	for (int i = 1; i <= 6; i++) {
		data[idx] = i;
		DFS1(idx + 1);
	}
}

void DFS2(int idx, int s)
{
	if (idx >= N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}
	for (int i = s; i <= 6; i++) {
		data[idx] = i;
		DFS2(idx + 1, i);
	}
}

void DFS3(int idx)
{
	if (idx >= N) {
		for (int i = 0; i < N; i++) {
			printf("%d ", data[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (used[i] == 1) continue;
		used[i] = 1;
		data[idx] = i;		
		DFS3(idx + 1);
		used[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	if (M == 1) {
		DFS1(0);
	}
	else if (M == 2) {
		DFS2(0, 1);
	}
	else if (M == 3) {
		DFS3(0);
	}

	return 0;
}