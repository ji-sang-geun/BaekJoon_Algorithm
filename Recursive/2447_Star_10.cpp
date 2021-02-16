#include <iostream>
using namespace std;

int current_N = 1; 

void recursive_if(int row, int col, int N) { 
	if (current_N != 3) { // current_N이 3이 아닐 경우
		current_N = current_N / 3; // current_N을 3으로 나눠줌
		if ((row % current_N >= current_N / 3 && col % current_N >= current_N / 3) && (row % current_N < current_N * 2 / 3 && col % current_N < current_N * 2 / 3)) { // 1/3 이상 2/3 미만 까지
			cout << " ";
		}
		else if ((row % current_N < current_N / 3 || col % current_N < current_N / 3) || (row % current_N >= current_N * 2 / 3 || col % current_N >= current_N * 2 / 3)) { // 나머지의 경우
			recursive_if(row, col, current_N); //
		}
	}
	else {
		cout << "*"; 
	}
}

void recursive(int row, int col, int N) {
	current_N = N;

	if (row < N) {
		if ((row % N >= N / 3 && col % N >= N / 3) && (row % N < N * 2 / 3 && col % N < N * 2 / 3)) { // 1/3 이상 2/3 미만의 경우
			cout << " ";
		}
		else if ((row % N < N / 3 || col % N < N / 3) || (row % N >= N * 2 / 3 || col % N >= N * 2 / 3)) { // 나머지 경우
			recursive_if(row, col, current_N); // 재귀 호출
		}
		recursive(row + 1, col, N);
	}
	else if (col < N - 1) {
		cout << "\n";
		recursive(0, col + 1, N);
	}
}

int main(void) {
	int N = 0;

	cin >> N;

	recursive(0, 0, N);
}