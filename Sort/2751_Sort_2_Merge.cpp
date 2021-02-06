/* 도움을 받은 사이트 : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html */

#include <iostream>
using namespace std; 

// 이것마저 Dynamically Allocation 해버리면, 시간 초과가 생겨버리므로, 밖으로 빼냄.
// 시간을 더 줄이고 싶다면 main 함수의 arr 마저 전역으로 설정.
int sort_result[1000001] = { 0, };

void merge(int* arr, int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 arr의 index
	int j = middle + 1; // 정렬된 오른쪽 arr의 index
	int k = left; // 정렬될 arr의 index

	// merge
	while (i <= middle && j <= right) { 
		if (arr[i] <= arr[j]) { 
			sort_result[k++] = arr[i++];
		}
		else if (arr[i] >= arr[j]) {
			sort_result[k++] = arr[j++];
		}
	}

	// merge하고 남은 값들 모두 copy
	if (i > middle) { 
		for (int l = j; l <= right; l++) {
			sort_result[k++] = arr[l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= middle; l++) {
			sort_result[k++] = arr[l];
		}
	}

	// sort 배열을 arr 배열로 재복사
	// left ~ right로 해야 O(NlogN) 성립, 0부터 시작하면 O(N^2)이 됨
	for (int l = left; l <= right; l++) {
		// 정렬된 내용을 다시 arr에 담아주는 이유 
		// 1. 이미 정렬된 부분을 merge한다 라는 로직을 지킴.
		// -> 안그러면 양쪽이 정렬되지 않은 상태에서 merge 시도
		arr[l] = sort_result[l];
	}

}

void sort(int *arr, int left, int right) {
	int middle = 0;

	// left <= right는 무한 재귀가 되므로, 사용하면 안됨
	if (left < right) {
		middle = (left + right) / 2; // 중간 위치 계산
		sort(arr, left, middle); // 앞쪽 정렬
		sort(arr, middle + 1, right); // 뒤쪽 정렬
		merge(arr, left, middle, right);
	}

}

int main(void) {
	int N = 0; // Initialize

	cin >> N;

	int* arr = new int[N]; // Dynamically Allocation Array

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, 0, N - 1); 

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}

	delete[] arr; 
}