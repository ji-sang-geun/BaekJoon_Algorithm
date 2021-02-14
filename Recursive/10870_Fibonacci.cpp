#include <iostream>
using namespace std;

int before_1 = 0, before_2 = 1; // 0?? 1??

void fibonacci(int start, int n) {

	if (start != n) {
		if (start % 2 == 1) before_1 = before_1 + before_2; // ?? ?? ?
		else if (start % 2 == 0) before_2 = before_1 + before_2; // ?? ?? ?
		fibonacci(start + 1, n); // ??
	}
	else if (start == n) {
		if (start % 2 == 1) cout << before_2; // ?? ???
		else if (start % 2 == 0) cout << before_1; // ?? ???
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