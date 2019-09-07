#include <stdio.h>


int coin[] = {500, 100, 50, 10};
int data[4];

int main()
{
	int N, retVal = 0;;
	scanf("%d", &N);
	for (int i = 0; i < 4; i++) {
		retVal += N / coin[i];
		N = N % coin[i];
	}
	printf("%d",retVal);

	return 0;
}