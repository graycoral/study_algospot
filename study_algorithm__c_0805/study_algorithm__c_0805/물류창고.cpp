
#include <iostream>
using namespace std;

int N; //��
int S; //�������
int C[50010]; //����
int Y[50010]; //�뷮

void Input_Data(void) {
	int i;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> C[i] >> Y[i];
	}
}

int main() {
	long long ans = -1;
	Input_Data();		// �Է� �Լ�

	// TODO : �ڵ带 �ۼ��ϼ���


	cout << ans << endl;	// ���� ���
	return 0;
}
