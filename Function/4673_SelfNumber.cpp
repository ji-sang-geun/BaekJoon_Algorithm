#include <iostream>
using namespace std;

void SelfNumber(int n) {
	int finder = 0, current_i = 0;

	int* arr = new int[n]; // Dynamically Allocation Array

	for (int i = 0; i < n; i++) {
		arr[i] = i+1; // �迭 ��ҿ� 1 ~ 10000���� ����
	}

	for (int i = 1; i <= n; i++) {
		finder = 0; // Initialize 

		// �� �ڸ��� + ���� ���� ����
		finder = i;
		current_i = i;
		while (current_i) {
			finder = finder + (current_i % 10);
			current_i = current_i / 10;
		}
		
		for (int j = 0; j < n; j++) { // finder�� 1~10000���� ����ִ� �迭 ��� ���ؼ� ������ ��Ҹ� -1�� ����
			if (finder == arr[j]) arr[j] = -1;
		}
	}

	for (int k = 0; k < n; k++) { // �迭 ��� �� -1�� �ƴ� �͸� ���
		if (arr[k] != -1) cout << arr[k] << endl;
	}

}

int main(void) {
	int number = 10000; // Initialize 

	SelfNumber(number);
}