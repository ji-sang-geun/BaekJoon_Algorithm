#include <iostream>
using namespace std;

int sort_result[100] = { 0, };
int arr[100] = { 0, };

void merge(int* arr, int left, int middle, int right) {
	int i = left; // ���ĵ� ���� arr�� index
	int j = middle + 1; // ���ĵ� ������ arr�� index
	int k = left; // ���ĵ� arr�� index


	// merge
	while (i <= middle && j <= right) {
		if (arr[i] >= arr[j]) {
			sort_result[k++] = arr[i++];
		}
		else if (arr[i] < arr[j]) {
			sort_result[k++] = arr[j++];
		}
	}
	
	// merge �ϰ� ���� �� copy
	if (i > middle) { // ������ �κ� ����
		for (int l = j; l <= right; l++) {
			sort_result[k++] = arr[l];
		}
	}
	else if (j > right) { // ���� �κ� ����
		for (int l = i; l <= middle; l++) {
			sort_result[k++] = arr[l];
		}
	}

	// sort �迭�� arr �迭�� �纹��
	for (int l = left; l <= right; l++) {
		arr[l] = sort_result[l];
	}

}

void sort(int* arr, int left, int right) {
	int middle = 0;

	// left < right�̾�� ��
	if (left < right) {
		middle = (left + right) / 2; // middle �� = (left + right) / 2
		sort(arr, left, middle); // ���ĵ� ���� index
		sort(arr, middle + 1, right); // ���ĵ� ������ index
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