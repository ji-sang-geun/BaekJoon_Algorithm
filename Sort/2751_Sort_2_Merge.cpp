/* ������ ���� ����Ʈ : https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html */

#include <iostream>
using namespace std; 

// �̰͸��� Dynamically Allocation �ع�����, �ð� �ʰ��� ���ܹ����Ƿ�, ������ ����.
// �ð��� �� ���̰� �ʹٸ� main �Լ��� arr ���� �������� ����.
int sort_result[1000001] = { 0, };

void merge(int* arr, int left, int middle, int right) {
	int i = left; // ���ĵ� ���� arr�� index
	int j = middle + 1; // ���ĵ� ������ arr�� index
	int k = left; // ���ĵ� arr�� index

	// merge
	while (i <= middle && j <= right) { 
		if (arr[i] <= arr[j]) { 
			sort_result[k++] = arr[i++];
		}
		else if (arr[i] >= arr[j]) {
			sort_result[k++] = arr[j++];
		}
	}

	// merge�ϰ� ���� ���� ��� copy
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

	// sort �迭�� arr �迭�� �纹��
	// left ~ right�� �ؾ� O(NlogN) ����, 0���� �����ϸ� O(N^2)�� ��
	for (int l = left; l <= right; l++) {
		// ���ĵ� ������ �ٽ� arr�� ����ִ� ���� 
		// 1. �̹� ���ĵ� �κ��� merge�Ѵ� ��� ������ ��Ŵ.
		// -> �ȱ׷��� ������ ���ĵ��� ���� ���¿��� merge �õ�
		arr[l] = sort_result[l];
	}

}

void sort(int *arr, int left, int right) {
	int middle = 0;

	// left <= right�� ���� ��Ͱ� �ǹǷ�, ����ϸ� �ȵ�
	if (left < right) {
		middle = (left + right) / 2; // �߰� ��ġ ���
		sort(arr, left, middle); // ���� ����
		sort(arr, middle + 1, right); // ���� ����
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