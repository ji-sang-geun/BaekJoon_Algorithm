#include <iostream>
using namespace std;

int arr[1001] = { 0, };
int sub_arr[1001] = { 0, };
int result[1001] = { 0, };

void sort(int* arr, int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int k = left;
	
	// 복사
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sub_arr[k++] = arr[i++];
		}
		else if (arr[i] > arr[j]) {
			sub_arr[k++] = arr[j++];
		}
	}

	// 남아있는 값들 복사
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sub_arr[k++] = arr[l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= middle; l++) {
			sub_arr[k++] = arr[l];
		}
	}

	// 임시 배열에서 원래 배열로 재복사
	for (int l = left; l <= right; l++) {
		arr[l] = sub_arr[l];
	}
}

void merge(int* arr, int left, int right) {
	int middle = 0;

	// left <= right는 무한 재귀가 되므로, 사용하면 안됨
	if (left < right) {
		middle = (left + right) / 2;
		merge(arr, left, middle);
		merge(arr, middle + 1, right);
		sort(arr, left, middle, right);
	}
}

int main(void) {
	int N = 0;
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	merge(arr, 0, N - 1);

	result[0] = arr[0];
	sum = result[0];
	for (int i = 1; i < N; i++) {
		result[i] = result[i-1] + arr[i];
		sum = sum + result[i];
	}

	cout << sum;

	return 0;
}