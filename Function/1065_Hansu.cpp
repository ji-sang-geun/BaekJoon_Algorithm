#include <iostream> 
using namespace std;

int Hansu(int n) {
	int count = 0;
	int number = 0, sub_number_10 = 0, sub_number_1 = 0;
	int sub = 1000; // sub�� 1000���� initialize (10 �̻����� initialize�ϸ� ��)

	for (int i = 1; i <= n; i++) {
		number = i; // ���� ���� ����
		if (number < 100) count++; // 100 ���� ���� ���� ��� �� �Ѽ��� �� �� �ֱ� ������ ��� count
		else if (number >= 100 && number < 1000) { // 100 ~ 999�� ��� 10���ڸ��� 1���ڸ��� ���̿� 100���ڸ��� 10���ڸ��� ���̸� ���� ������ count
			while (number / 10 > 0) {
				sub_number_1 = number % 10;
				number = number / 10;
				sub_number_10 = number % 10;
				if (sub == 1000) {
					sub = sub_number_10 - sub_number_1;
				}
				else if (sub != 1000) {
					if (sub == sub_number_10 - sub_number_1) count++;
				}
			}
		}
		sub = 1000; // sub initialize
	}

	return count; // return
}

int main(void) {
	int N = 0; // Initialize

	cin >> N;

	cout << Hansu(N);

	return 0;
}