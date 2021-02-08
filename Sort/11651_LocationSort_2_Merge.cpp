#include <iostream>
using namespace std;

int arr[2][100001] = { 0, }; // 원래 배열
int sort_arr[2][100001] = { 0, }; // 임시 배열

void merge(int(*arr)[100001], int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 배열 index
	int j = middle + 1; // 정렬된 오른쪽 배열 index
	int k = left; // 정렬될 배열 index

	// merge
	while (i <= middle && j <= right) {
		if (arr[1][i] < arr[1][j]) {
			sort_arr[0][k] = arr[0][i];
			sort_arr[1][k++] = arr[1][i++];
		}
		else if (arr[1][i] == arr[1][j]) {
			if (arr[0][i] < arr[0][j]) {
				sort_arr[0][k] = arr[0][i];
				sort_arr[1][k++] = arr[1][i++];
			}
			else if (arr[0][i] > arr[0][j]) {
				sort_arr[0][k] = arr[0][j];
				sort_arr[1][k++] = arr[1][j++];
			}
		}
		else if (arr[1][i] > arr[1][j]) {
			sort_arr[0][k] = arr[0][j];
			sort_arr[1][k++] = arr[1][j++];
		}
	}

	// 남아있는 값들 복사
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sort_arr[0][k] = arr[0][l];
			sort_arr[1][k++] = arr[1][l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= middle; l++) {
			sort_arr[0][k] = arr[0][l];
			sort_arr[1][k++] = arr[1][l];
		}
	}

	// 임시 배열에서 원래 배열로 재복사
	for (int l = left; l <= right; l++) {
		arr[0][l] = sort_arr[0][l];
		arr[1][l] = sort_arr[1][l];
	}
}

void sort(int(*arr)[100001], int left, int right) {
	int middle = 0;

	// left <= right는 무한 재귀가 되므로, 사용하면 안됨
	if (left < right) {
		middle = (left + right) / 2;
		sort(arr, left, middle);
		sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

int main(void) {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[0][i] >> arr[1][i];
	}

	sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[0][i] << " " << arr[1][i] << "\n";
	}

	return 0;
}