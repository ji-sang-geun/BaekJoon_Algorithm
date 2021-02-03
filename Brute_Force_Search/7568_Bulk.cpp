#include <iostream>
using namespace std;

void Bulk(int* x, int* y, int N) {
	int* arr = new int[N](); // Dynamically allocation array

	// 자신보다 더 큰 덩치를 가진 사람 수 찾기
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (x[i] > x[j] && y[i] > y[j]) {
				arr[j]++;
			}
			else if (x[i] < x[j] && y[i] < y[j]) {
				arr[i]++;
			}
		}
	}

	// output
	for (int i = 0; i < N; i++) {
		cout << arr[i]+1 << " ";
	}

	delete[] arr;
}

int main(void) {
	int N = 0; // initialize
	
	cin >> N;

	int* x = new int[N];
	int* y = new int[N];

	// input
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	} 

	Bulk(x, y, N);

	delete[] x;
	delete[] y;
	
	return 0;
}