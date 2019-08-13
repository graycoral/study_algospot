#include <stdio.h>
#define MAXN	((int)100*100+10)

struct Q {
	int data;
	int idx;
};
int wp, rp;

struct Q queue[MAXN];

void push(int data, int idx) {
	queue[wp].data = data;
	queue[wp++].idx = idx;
}

void pop() { wp++; }
int size() { return wp - rp; }
struct Q front() {
	return queue[rp];
}

int N;
int pri[MAXN];
int num, idx;

void input()
{
	scanf("%d %d", &num, &idx);
	for (int i = 0; i < num; i++) {
		int tmPri;
		scanf("%d", &tmPri);
		push(tmPri, i);
		pri[tmPri]++;
	}
}

void sol()
{
	int cnt = 0;
	for (int i = 9; i > 0; i--) {
		while (pri[i]-- > 0) {
			struct Q cur = front(); pop();
			if (cur.data != i) {
				push(cur.data, cur.idx);
			}
			else {
				if (cur.data == num && cur.idx == idx) {
					printf("%d\n", ++cnt);
					return;
				}
			}
		}
	}

	printf("*** TEST : %d\n", cnt);
}

int main()
{
	scanf("%d", &N);

	while (N--) {
		input();
		sol();
	}
	return 0;
}