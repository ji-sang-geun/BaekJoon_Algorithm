#include <iostream>
using namespace std;

string input_arr[20001] = { "" }; // input을 담당하는 문자열 배열
string arr[20001] = { "" }; // input에서 중복을 제거한 항목을 받을 배열
string sort_arr[20001] = { "" }; // 임시로 정렬된 배열

void merge(string* arr, int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 arr 배열의 index
	int j = middle + 1; // 정렬된 오른쪽 arr 배열의 index
	int k = left; // 정렬될 arr의 index

	// merge
	while (i <= middle && j <= right) {
		if (arr[i].length() < arr[j].length()) {
			sort_arr[k++] = arr[i++];
		}
		else if (arr[i].length() > arr[j].length()) {
			sort_arr[k++] = arr[j++];
		}
		else if (arr[i].length() == arr[j].length()) {
			if (arr[i] < arr[j]) {
				sort_arr[k++] = arr[i++];
			}
			else if (arr[i] > arr[j]) {
				sort_arr[k++] = arr[j++];
			}
		}
	}

	// merge하고 남은 것들을 sort_arr에 넣어줌
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sort_arr[k++] = arr[l];
		}
	}
	else if (j > right) {
		for (int l = i; l <= middle; l++) {
			sort_arr[k++] = arr[l];
		}
	}

	// arr배열로 sort_arr의 요소들을 재복사
	for (int l = left; l <= right; l++) {
		arr[l] = sort_arr[l];
	}
}

void sort(string* arr, int left, int right) {
	int middle = 0;

	if (left < right) {
		middle = (left + right) / 2;
		sort(arr, left, middle);
		sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

int main(void) {
	int N = 0; // 항목 수
	int token = 0, copy_N = 0; // token은 중복을 찾아주기 위한 것, copy_N은 N을 복사한 것으로 중복된 것이 있을 때 마다 -1 
	int k = 0; // arr배열 index

	cin >> N;
	copy_N = N;

	for (int i = 0; i < N; i++) {
		token = 0;
		cin >> input_arr[i];

		for (int j = 0; j < i; j++) {
			if (input_arr[i] == input_arr[j]) { // 중복된 것이 있을 경우
				token = 1;
				copy_N--;
				break; // 반복문 탈출
			}
		}

		if (token != 1) { // input_arr의 요소들 중 중복 제외한 요소들을 arr 배열로 복사
			arr[k++] = input_arr[i];
		}
	}

	sort(arr, 0, copy_N - 1); 

	for (int i = 0; i < copy_N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}