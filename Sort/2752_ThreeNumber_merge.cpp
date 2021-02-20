/* 세 수만 정렬 하는 것이지만 병합 정렬을 사용했음 */

#include <iostream>
using namespace std;

int arr[3] = { 0, };
int sub_arr[3] = { 0, };

void sort(int* arr, int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int k = left;

	// 조건에 맞으면 배열에 복사
	while (i <= middle && j <= right) {
		if (arr[i] < arr[j]) {
			sub_arr[k++] = arr[i++];
		}
		else if (arr[i] >= arr[j]) {
			sub_arr[k++] = arr[j++];
		}
	}

	// 남아있는 값들 배열에 복사
	if (j > right) {
		for (int l = i; l <= middle; l++) {
			sub_arr[k++] = arr[l];
		}
	}
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sub_arr[k++] = arr[l];
		}
	}

	// 원래 배열에 재복사
	for (int l = left; l <= right; l++) {
		arr[l] = sub_arr[l];
	}
}

void merge(int* arr, int left, int right) {
	int middle = 0;

	// left <= right가 되면 무한 재귀가 됨
	if (left < right) {
		middle = (left + right) / 2;
		merge(arr, left, middle);
		merge(arr, middle + 1, right);
		sort(arr, left, middle, right);
	}
}

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	merge(arr, 0, 2);

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}