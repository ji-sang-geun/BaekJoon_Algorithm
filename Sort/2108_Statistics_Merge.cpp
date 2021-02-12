#include <iostream>
using namespace std;

int arr[500001] = { 0, }; // 정렬된 배열
int sort_arr[500001] = { 0, }; // 임시 배열
int count_arr[500001] = { 0, }; // 최빈값을 구하기 위한 배열

void merge(int* arr, int left, int middle, int right) {
	int i = left; // 정렬된 왼쪽 배열의 index
	int j = middle + 1; // 정렬된 오른쪽 배열의 index
	int k = left; // 정렬될 배열의 index

	// merge
	while (i <= middle && j <= right) {
		if (arr[i] <= arr[j]) {
			sort_arr[k++] = arr[i++];
		}
		else if (arr[i] > arr[j]) {
			sort_arr[k++] = arr[j++];
		}
	}

	// 남은 값들 복사
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

	// 임시배열에서 원래 배열로 재복사
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
	int average = 0; // 산술평균
	int median = 0; // 중앙값
	int mode = 0, mode_count = 0; // 최빈값
	int range = 0; // 범위
	int index = 0, token = 1; 

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		average = average + arr[i]; // arr[i]의 총합 구하기
	}

	sort(arr, 0, N - 1); // 병합 정렬

	median = arr[N / 2];  // 정렬된 값들 중 중앙값 구하기

	for (int i = 0; i < N; i++) {
		if (arr[i] == arr[i + 1]) { // 다음번 arr 요소가 현재 arr 요소와 같을 때
			count_arr[index]++; 
			token++; // token이 1증가 (중복된 것을 증명하기 위함)
		}
		else if (arr[i] != arr[i + 1]) { // 다음번 arr 요소가 현재 arr 요소와 같지 않을 경우
			count_arr[index]++;
			if (token == 1) { // token이 1인 경우, 중복된 것이 아니기 때문에 
				index++; // index 1만 증가
				token = 1; // token은 1로 다시 초기화
			}
			else if (token != 1) { // 중복된 경우
				index = index + token; // token만큼 index 증가
				token = 1;
			}
		}
	}

	mode_count = count_arr[0];
	mode = arr[0];
	for (int i = 1; i < N; i++) { // 최빈값들 중 가장 작은 숫자 구하기 
		if (mode_count < count_arr[i]) {
			mode_count = count_arr[i];
			mode = arr[i];
		}
	}

	for (int j = 0; j < N; j++) { // 최빈값들 중 두번째로 작은 숫자 구하기
		if (mode != arr[j] && mode_count == count_arr[j]) {
			mode = arr[j];
			break;
		}
	}

	if (N > 1) { // N이 1보다 크면 최댓값에서 최솟값을 빼 범위 구함
		range = arr[N - 1] - arr[0];
	}
	else if (N == 1) { // N이 1이면 범위는 0임
		range = 0;
	}

	cout << fixed;
	cout.precision(0); // 소숫점 첫 째자리에서 반올림
	cout << (double)average / N << "\n"; 

	cout << median << "\n";
	cout << mode << "\n";
	cout << range << "\n";

	return 0;
}