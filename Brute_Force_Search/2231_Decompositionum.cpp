#include <iostream>
using namespace std;

int DecompositionNum(int sum) {

	int num = 0;
	int current = 0;
	int result = 0;

	for (int i = 1; i < sum; i++) { // sum 이하인 수들 i
		current = i; // 현재 자연수
		num = current; // 분해당할 수
		result = num; // sum과 비교할 수
		while (num) { 
			result = num % 10 + result;
			num = num / 10; // 10 이상이면 다음 분해를 위해 나눔
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