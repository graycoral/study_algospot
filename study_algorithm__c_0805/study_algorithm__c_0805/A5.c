#include <stdio.h>
#include <stdlib.h>

struct Data {
	int val;
	int idx;
};

int compare(const void* a, const void* b)
{
	struct Data* x = a;
	struct Data* y = b;

	if (x->val == y->val) return x->idx - y->idx;
	return y->val - x->val;
}

int main()
{
	int N;
	struct Data q[30000];
	scanf("%d", &N);	

	for (int i = 0; i < N; i++) {
		scanf("%d", &(q[i].val));
		q[i].idx = i;
	}

	qsort(&q, N, sizeof(q[0]), compare);

	for (int i = 0; i < 3; i++) {
		printf("%d ", q[i].idx + 1);
	}

	return 0;
}