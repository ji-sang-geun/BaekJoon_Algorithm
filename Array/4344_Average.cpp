#include <iostream>
using namespace std;

double Average_Over(int N) {
	int *arr = new int[N]; // Dinamically allocating arrays
	int Sum_Score = 0; // Initialize
	int Over = 0;

	for (int j = 0; j < N; j++) { // ��� ã��
		cin >> arr[j];
		Sum_Score = Sum_Score + arr[j];
	}

	for (int k = 0; k < N; k++) { // ��� �̻��� ��� ã��
		if (arr[k] > (double)Sum_Score / N) Over++;
	}

	delete[] arr;

	return Over / (double)N * 100; // ��ȯ
}

int main(void) {
	int C = 0, N = 0;

	cin >> C; // Test Case
	
	for (int i = 0; i < C; i++) {
		cin >> N; // Student's Number
		cout << fixed;
		cout.precision(3); // cout << fixed ���ְ�, cout.precision(5)�ص� �� => �Ҽ��� ��° �ڸ����� ���
		cout << (double)Average_Over(N)<< "%" << endl;
	}

	return 0; 
}