#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int count_arr[10001] = { 0, };

void counting_sort(int N) {

	int num = 0, max = 0;
	int index = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		
		// max를 찾아서 배열 범위 설정
		if (max < num) {
			max = num;
		}
		// 입력한 num 순서의 count 1증가
		count_arr[num]++;
	}

	for (int i = 0; i <= max; i++) {
		// count_arr[i]가 0이 아니란 것은 정렬할 숫자가 있다는 것을 의미
		while (count_arr[i] != 0) {
			// 출력
			printf("%d \n", i);
			// count_arr 1 감소
			count_arr[i]--;
		}
	}
}

int main(void) {
	int N = 0;

	scanf("%d", &N);

	counting_sort(N);
}