#include <iostream> 
using namespace std;

int Hansu(int n) {
	int count = 0;
	int number = 0, sub_number_10 = 0, sub_number_1 = 0;
	int sub = 1000; // sub를 1000으로 initialize (10 이상으로 initialize하면 됨)

	for (int i = 1; i <= n; i++) {
		number = i; // 현재 숫자 복사
		if (number < 100) count++; // 100 보다 작은 경우는 모두 다 한수가 될 수 있기 때문에 모두 count
		else if (number >= 100 && number < 1000) { // 100 ~ 999의 경우 10의자리와 1의자리의 차이와 100의자리와 10의자리의 차이를 비교해 같으면 count
			while (number / 10 > 0) {
				sub_number_1 = number % 10;
				number = number / 10;
				sub_number_10 = number % 10;
				if (sub == 1000) {
					sub = sub_number_10 - sub_number_1;
				}
				else if (sub != 1000) {
					if (sub == sub_number_10 - sub_number_1) count++;
				}
			}
		}
		sub = 1000; // sub initialize
	}

	return count; // return
}

int main(void) {
	int N = 0; // Initialize

	cin >> N;

	cout << Hansu(N);

	return 0;
}