#include <iostream>
using namespace std;

double Average_Over(int N) {
	int *arr = new int[N]; // Dinamically allocating arrays
	int Sum_Score = 0; // Initialize
	int Over = 0;

	for (int j = 0; j < N; j++) { // 평균 찾기
		cin >> arr[j];
		Sum_Score = Sum_Score + arr[j];
	}

	for (int k = 0; k < N; k++) { // 평균 이상인 사람 찾기
		if (arr[k] > (double)Sum_Score / N) Over++;
	}

	delete[] arr;

	return Over / (double)N * 100; // 반환
}

int main(void) {
	int C = 0, N = 0;

	cin >> C; // Test Case
	
	for (int i = 0; i < C; i++) {
		cin >> N; // Student's Number
		cout << fixed;
		cout.precision(3); // cout << fixed 없애고, cout.precision(5)해도 됨 => 소수점 셋째 자리까지 출력
		cout << (double)Average_Over(N)<< "%" << endl;
	}

	return 0; 
}