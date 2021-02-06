#include <iostream>
using namespace std;

int sort_result[100] = { 0, };
int arr[100] = { 0, };

void merge(int* arr, int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 arr의 index
	int j = middle + 1; // 정렬된 오른쪽 arr의 index
	int k = left; // 정렬될 arr의 index


	// merge
	while (i <= middle && j <= right) {
		if (arr[i] >= arr[j]) {
			sort_result[k++] = arr[i++];
		}
		else if (arr[i] < arr[j]) {
			sort_result[k++] = arr[j++];
		}
	}
	
	// merge 하고 남은 값 copy
	if (i > middle) { // 오른쪽 부분 정렬
		for (int l = j; l <= right; l++) {
			sort_result[k++] = arr[l];
		}
	}
	else if (j > right) { // 왼쪽 부분 정렬
		for (int l = i; l <= middle; l++) {
			sort_result[k++] = arr[l];
		}
	}

	// sort 배열을 arr 배열로 재복사
	for (int l = left; l <= right; l++) {
		arr[l] = sort_result[l];
	}

}

void sort(int* arr, int left, int right) {
	int middle = 0;

	// left < right이어야 함
	if (left < right) {
		middle = (left + right) / 2; // middle 값 = (left + right) / 2
		sort(arr, left, middle); // 정렬된 왼쪽 index
		sort(arr, middle + 1, right); // 정렬된 오른쪽 index
		merge(arr, left, middle, right); 
	}
}

int main(void) {
	int N = 0; // Initialize
	int index = 0;

	cin >> N;

	while (N != 0) {
		arr[index] = N % 10;
		N = N / 10;
		index++;
	}

	sort(arr, 0, index - 1);

	for (int i = 0; i < index; i++) {
		cout << arr[i];
	}


}