#include <iostream>
using namespace std;

int arr[500001] = { 0, }; // ���ĵ� �迭
int sort_arr[500001] = { 0, }; // �ӽ� �迭
int count_arr[500001] = { 0, }; // �ֺ��� ���ϱ� ���� �迭

void merge(int* arr, int left, int middle, int right) {
	int i = left; // ���ĵ� ���� �迭�� index
	int j = middle + 1; // ���ĵ� ������ �迭�� index
	int k = left; // ���ĵ� �迭�� index

	// merge
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sort_arr[k++] = arr[i++];
		}
		else if (arr[i] > arr[j]) {
			sort_arr[k++] = arr[j++];
		}
	}

	// ���� ���� ����
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

	// �ӽù迭���� ���� �迭�� �纹��
	for (int l = left; l <= right; l++) {
		arr[l] = sort_arr[l];
	}

}

void sort(int* arr, int left, int right) {
	int middle = 0;

	if (left < right) {
		middle = (left + right) / 2;
		sort(arr, left, middle);
		sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int average = 0; // ������
	int median = 0; // �߾Ӱ�
	int mode = 0, mode_count = 0; // �ֺ�
	int range = 0; // ����
	int index = 0, token = 1; 

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		average = average + arr[i]; // arr[i]�� ���� ���ϱ�
	}

	sort(arr, 0, N - 1); // ���� ����

	median = arr[N / 2];  // ���ĵ� ���� �� �߾Ӱ� ���ϱ�

	for (int i = 0; i < N; i++) {
		if (arr[i] == arr[i + 1]) { // ������ arr ��Ұ� ���� arr ��ҿ� ���� ��
			count_arr[index]++; 
			token++; // token�� 1���� (�ߺ��� ���� �����ϱ� ����)
		}
		else if (arr[i] != arr[i + 1]) { // ������ arr ��Ұ� ���� arr ��ҿ� ���� ���� ���
			count_arr[index]++;
			if (token == 1) { // token�� 1�� ���, �ߺ��� ���� �ƴϱ� ������ 
				index++; // index 1�� ����
				token = 1; // token�� 1�� �ٽ� �ʱ�ȭ
			}
			else if (token != 1) { // �ߺ��� ���
				index = index + token; // token��ŭ index ����
				token = 1;
			}
		}
	}

	mode_count = count_arr[0];
	mode = arr[0];
	for (int i = 1; i < N; i++) { // �ֺ󰪵� �� ���� ���� ���� ���ϱ� 
		if (mode_count < count_arr[i]) {
			mode_count = count_arr[i];
			mode = arr[i];
		}
	}

	for (int j = 0; j < N; j++) { // �ֺ󰪵� �� �ι�°�� ���� ���� ���ϱ�
		if (mode != arr[j] && mode_count == count_arr[j]) {
			mode = arr[j];
			break;
		}
	}

	if (N > 1) { // N�� 1���� ũ�� �ִ񰪿��� �ּڰ��� �� ���� ����
		range = arr[N - 1] - arr[0];
	}
	else if (N == 1) { // N�� 1�̸� ������ 0��
		range = 0;
	}

	cout << fixed;
	cout.precision(0); // �Ҽ��� ù °�ڸ����� �ݿø�
	cout << (double)average / N << "\n"; 

	cout << median << "\n";
	cout << mode << "\n";
	cout << range << "\n";

	return 0;
}