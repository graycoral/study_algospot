#include <iostream>
#include <string>
using namespace std;

int N;//�׽�Ʈ ���̽� ��
int B;//����
char S[100];//ù ��° ����
char D[100];//�� ��° ����

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
		InputData();//�Է� �Լ�
		//	�ڵ带 �ۼ��ϼ���
		sol();
	}
	return 0;
}