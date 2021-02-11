#include <iostream>
using namespace std;

string input_arr[20001] = { "" }; // input�� ����ϴ� ���ڿ� �迭
string arr[20001] = { "" }; // input���� �ߺ��� ������ �׸��� ���� �迭
string sort_arr[20001] = { "" }; // �ӽ÷� ���ĵ� �迭

void merge(string* arr, int left, int middle, int right) {
	int i = left; // ���ĵ� ���� arr �迭�� index
	int j = middle + 1; // ���ĵ� ������ arr �迭�� index
	int k = left; // ���ĵ� arr�� index

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

	// merge�ϰ� ���� �͵��� sort_arr�� �־���
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

	// arr�迭�� sort_arr�� ��ҵ��� �纹��
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
	int N = 0; // �׸� ��
	int token = 0, copy_N = 0; // token�� �ߺ��� ã���ֱ� ���� ��, copy_N�� N�� ������ ������ �ߺ��� ���� ���� �� ���� -1 
	int k = 0; // arr�迭 index

	cin >> N;
	copy_N = N;

	for (int i = 0; i < N; i++) {
		token = 0;
		cin >> input_arr[i];

		for (int j = 0; j < i; j++) {
			if (input_arr[i] == input_arr[j]) { // �ߺ��� ���� ���� ���
				token = 1;
				copy_N--;
				break; // �ݺ��� Ż��
			}
		}

		if (token != 1) { // input_arr�� ��ҵ� �� �ߺ� ������ ��ҵ��� arr �迭�� ����
			arr[k++] = input_arr[i];
		}
	}

	sort(arr, 0, copy_N - 1); 

	for (int i = 0; i < copy_N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}