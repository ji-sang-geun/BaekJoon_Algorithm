#include <iostream>
using namespace std;

int before_1 = 0, before_2 = 1; // 0번째 1번째 

void fibonacci(int start, int n) {

	if (start != n) {
		if (start % 2 == 1) before_1 = before_1 + before_2; // 홀수 번일 때
		else if (start % 2 == 0) before_2 = before_1 + before_2; // 짝수 번일 때
		fibonacci(start + 1, n); // 재귀
	}
	else if (start == n) {
		if (start % 2 == 1) cout << before_2; // 홀수 마지막
		else if (start % 2 == 0) cout << before_1; // 짝수 마지막
		return; 
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;

	cin >> n;
	
	if (n == 0) {
		cout << before_1;
		return 0;
	}

	fibonacci(1, n);

	return 0;
}