#include <iostream>
using namespace std;

int arr[2][100001] = { 0, }; // ���� �迭
int sort_arr[2][1000001] = { 0, }; // �ӽ� �迭

void merge(int (*arr)[100001], int left, int middle, int right) {
	int i = left; // ���ĵ� ���� �迭 index
	int j = middle + 1; // ���ĵ� ������ �迭 index
	int k = left; // ���ĵ� �迭 index

	// merge
	while (i <= middle && j <= right) {
		if (arr[0][i] < arr[0][j]) {
			sort_arr[0][k] = arr[0][i];
			sort_arr[1][k++] = arr[1][i++];
		}
		else if (arr[0][i] == arr[0][j]) {
			if (arr[1][i] < arr[1][j]) {
				sort_arr[0][k] = arr[0][i];
				sort_arr[1][k++] = arr[1][i++];
			}
			else if (arr[1][i] > arr[1][j]) {
				sort_arr[0][k] = arr[0][j];
				sort_arr[1][k++] = arr[1][j++];
			}
		}
		else if (arr[0][i] > arr[0][j]) {
			sort_arr[0][k] = arr[0][j];
			sort_arr[1][k++] = arr[1][j++];

		}

	}

	// �����ִ� ���� ����
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

	// �ӽ� �迭���� ���� �迭�� �纹��
	for (int l = left; l <= right; l++) {
		arr[0][l] = sort_arr[0][l];
		arr[1][l] = sort_arr[1][l];
	}
}

void sort(int (*arr)[100001], int left, int right) {
	int middle = 0;

	// left <= right�� ���� ��Ͱ� �ǹǷ�, ����ϸ� �ȵ�
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
		cin >> arr[0][i] >> arr[1][i];
	}

	sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[0][i] << " " << arr[1][i] << "\n";
	}

	return 0;
}