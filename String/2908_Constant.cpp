#include <iostream>
using namespace std;

int main(void) {
	int X1, X2, size =0;
	int num[2][3];

	cin >> X1 >> X2;

	// X1�� X2�� ���� �ڸ��� ��
	// X1�� X2�� ������ ���� �迭�� ����
	// �迭�� ���ڸ� �ϳ��� ���� �� ���� size 1 ����
	while(X1 && X2) {
		num[0][size] = X1 % 10;
		X1 = X1 / 10;
		num[1][size] = X2 % 10;
		X2 = X2 / 10;
		size++;
	}

	// ���� ���� ���� �����Ƿ�, ==�� ����
	// ���� �� ū ���� ������ ����ϰ� �ݺ��� Ż��
	for (int i = 0; i < size; i++) {
		if (num[0][i] > num[1][i]) {
			for (int i = 0; i < size; i++) {
				cout << num[0][i];
			}
			break;
		}
		else if (num[0][i] < num[1][i]) {
			for (int i = 0; i < size; i++) {
				cout << num[1][i];
			}
			break;
		}
	}

	return 0;
}