#include <iostream>
using namespace std;

int arr[100001] = { 0, }; // 나잇값을 넣는 원래 배열
int sort_arr[100001] = { 0, }; // 정렬된 나잇값을 넣는 임시 배열
string name_arr[100001] = { "" }; // 이름값을 넣는 문자열 배열
string name_sort_arr[100001] = { "" }; // 정렬한 이름값을 넣는 임시 배열

void merge(int* arr, int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 배열 index
	int j = middle + 1; // 정렬된 오른쪽 배열 index
	int k = left; // 정렬될 배열 index
	
	// merge
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sort_arr[k] = arr[i];
			name_sort_arr[k++] = name_arr[i++];
		}
		else if (arr[i] > arr[j]) {
			sort_arr[k] = arr[j];
			name_sort_arr[k++] = name_arr[j++];
		}
	}

	// 남아있는 값들 복사
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sort_arr[k] = arr[l];
			name_sort_arr[k++] = name_arr[l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= middle; l++) {
			sort_arr[k] = arr[l];
			name_sort_arr[k++] = name_arr[l];
		}
	}

	// 임시 배열에서 원래 배열로 재복사
	for (int l = left; l <= right; l++) {
		arr[l] = sort_arr[l];
		name_arr[l] = name_sort_arr[l];
	}
}

void sort(int* arr, int left, int right) {
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
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i] >> name_arr[i];
	}

	sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " " << name_arr[i] << "\n";
	}

	return 0;
}