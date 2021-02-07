#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int count_arr[10001] = { 0, };

void counting_sort(int N) {

	int num = 0, max = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (max < num) {
			max = num;
		}
		count_arr[num]++;
	}

	for (int i = 0; i <= max; i++) {
		while (count_arr[i] != 0) {
			printf("%d \n", i);
			index++;
			count_arr[i]--;
		}
	}
}

int main(void) {
	int N = 0;

	scanf("%d", &N);

	counting_sort(N);
}