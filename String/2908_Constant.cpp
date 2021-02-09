#include <iostream>
using namespace std;

int main(void) {
	int X1, X2, size =0;
	int num[2][3];

	cin >> X1 >> X2;

	// X1과 X2가 같은 자리수 임
	// X1과 X2를 리버스 시켜 배열에 넣음
	// 배열에 숫자를 하나씩 넣을 때 마다 size 1 증가
	while(X1 && X2) {
		num[0][size] = X1 % 10;
		X1 = X1 / 10;
		num[1][size] = X2 % 10;
		X2 = X2 / 10;
		size++;
	}

	// 같은 수는 없다 했으므로, ==는 제외
	// 만약 더 큰 수가 나오면 출력하고 반복문 탈출
	for (int i = 0; i < size; i++) {
		if (num[0][i] > num[1][i]) {
			for (int i = 0; i < size; i++) {
				cout << num[0][i];
			}
			break;
		}
		else if (num[0][i] < num[1][i]) {
			for (int i = 0; i < size; i++) {
				cout << num[1][i];
			}
			break;
		}
	}

	return 0;
}