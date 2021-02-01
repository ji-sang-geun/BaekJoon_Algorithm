#include <iostream>
using namespace std;
// 재귀 한번 사용해볼 것

int sum(int N, int M) {
	int* arr = new int[N]; // dynamically allocating
	int number = 0, max = 0; // initialize

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				number = arr[i] + arr[j] + arr[k];
				if (number < M) {
					if (number >= max) {
						max = number;
					}
					else if (number < max) {
						continue;
					}
				}
				else if (number > M) number = 0;
				else if (number == M) return number;
			}
		}
	}

	delete[] arr;

	return max;
}

int main(void) {
	int N = 0, M = 0; // initialize
	
	cin >> N >> M;
	
	cout << sum(N, M);

	return 0;
}