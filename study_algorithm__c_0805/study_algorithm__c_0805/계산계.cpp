#include <iostream>
#include <string>
using namespace std;

int N;//테스트 케이스 수
int B;//진법
char S[100];//첫 번째 정수
char D[100];//두 번째 정수

void InputData() {
	cin >> B >> S >> D;
}

void sol()
{
	while (N--) {
		if (S && D)	cout << "0\n";
		
	}
}

int main() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		InputData();//입력 함수
		//	코드를 작성하세요
		sol();
	}
	return 0;
}