#include <iostream>
using namespace std;

int DecompositionNum(int sum) {

	int num = 0;
	int current = 0;
	int result = 0;

	for (int i = 1; i < sum; i++) { // sum ������ ���� i
		current = i; // ���� �ڿ���
		num = current; // ���ش��� ��
		result = num; // sum�� ���� ��
		while (num) { 
			result = num % 10 + result;
			num = num / 10; // 10 �̻��̸� ���� ���ظ� ���� ����
		}
		if (result == sum) { // true
			return current; // current return
		}
	}

	return 0; // 0 return
}

int main(void) {
	int sum = 0; // initialize 

	cin >> sum;

	cout << DecompositionNum(sum);

	return 0;
}