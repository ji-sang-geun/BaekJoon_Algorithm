#include <iostream>
using namespace std;

void SelfNumber(int n) {
	int finder = 0, current_i = 0;

	int* arr = new int[n]; // Dynamically Allocation Array

	for (int i = 0; i < n; i++) {
		arr[i] = i+1; // 배열 요소에 1 ~ 10000까지 대입
	}

	for (int i = 1; i <= n; i++) {
		finder = 0; // Initialize 

		// 각 자리수 + 원래 수를 더함
		finder = i;
		current_i = i;
		while (current_i) {
			finder = finder + (current_i % 10);
			current_i = current_i / 10;
		}
		
		for (int j = 0; j < n; j++) { // finder와 1~10000까지 들어있는 배열 요소 비교해서 같으면 요소를 -1로 대입
			if (finder == arr[j]) arr[j] = -1;
		}
	}

	for (int k = 0; k < n; k++) { // 배열 요소 중 -1이 아닌 것만 출력
		if (arr[k] != -1) cout << arr[k] << endl;
	}

}

int main(void) {
	int number = 10000; // Initialize 

	SelfNumber(number);
}