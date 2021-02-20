#include <iostream>
using namespace std;
string name_arr[100001] = { "" }; // 이름 집어넣는 배열
string sub_name_arr[100001] = { "" };
int arr[100001][3] = { 0, }; // 국영수 점수 집어넣는 배열
int sub_arr[100001][3] = { 0, };

void sort(int(* arr)[3], int left, int middle, int right) {
	int i = left;
	int j = middle + 1;
	int k = left;

	// 조건에 맞는 경우 배열에 복사 (나중에 줄일 예정)
	while (i <= middle && j <= right) {
		if (arr[i][0] > arr[j][0]) {
			sub_name_arr[k] = name_arr[i];
			sub_arr[k][0] = arr[i][0];
			sub_arr[k][1] = arr[i][1];
			sub_arr[k++][2] = arr[i++][2];
		}
		else if (arr[i][0] < arr[j][0]) {
			sub_name_arr[k] = name_arr[j];
			sub_arr[k][0] = arr[j][0];
			sub_arr[k][1] = arr[j][1];
			sub_arr[k++][2] = arr[j++][2];
		}
		else if (arr[i][0] == arr[j][0]) {
			sub_arr[k][0] = arr[i][0];

			if (arr[i][1] < arr[j][1]) {
				sub_name_arr[k] = name_arr[i];
				sub_arr[k][1] = arr[i][1];
				sub_arr[k++][2] = arr[i++][2];
			}
			else if (arr[i][1] > arr[j][1]) {
				sub_name_arr[k] = name_arr[j];
				sub_arr[k][1] = arr[j][1];
				sub_arr[k++][2] = arr[j++][2];
			}
			else if (arr[i][1] == arr[j][1]) {
				sub_arr[k][0] = arr[i][0];
				sub_arr[k][1] = arr[i][1];

				if (arr[i][2] > arr[j][2]) {
					sub_name_arr[k] = name_arr[i];
					sub_arr[k++][2] = arr[i++][2];
				}
				else if (arr[i][2] < arr[j][2]) {
					sub_name_arr[k] = name_arr[j];
					sub_arr[k++][2] = arr[j++][2];
				}
				else if (arr[i][2] == arr[j][2]) {
					sub_arr[k][0] = arr[i][0];
					sub_arr[k][1] = arr[j][1];
					sub_arr[k][2] = arr[j][2];
					if (name_arr[i] <= name_arr[j]) {
						sub_name_arr[k++] = name_arr[i++];
					}
					else if (name_arr[i] > name_arr[j]) {
						sub_name_arr[k++] = name_arr[j++];
					}
				}
			}
		}
	}

	// 남는 값들 배열에 복사
	if (i > middle) {
		for (int l = j; l <= right; l++) {
			sub_name_arr[k] = name_arr[l];
			sub_arr[k][0] = arr[l][0];
			sub_arr[k][1] = arr[l][1];
			sub_arr[k++][2] = arr[l][2];
		}
	}
	if (j > right) {
		for (int l = i; l <= middle; l++) {
			sub_name_arr[k] = name_arr[l];
			sub_arr[k][0] = arr[l][0];
			sub_arr[k][1] = arr[l][1];
			sub_arr[k++][2] = arr[l][2];
		}
	}

	// 원래 배열에 재복사
	for (int l = left; l <= right; l++) {
		name_arr[l] = sub_name_arr[l];
		arr[l][0] = sub_arr[l][0];
		arr[l][1] = sub_arr[l][1];
		arr[l][2] = sub_arr[l][2];
	}

}

void merge(int(* arr)[3], int left, int right) {
	int middle = 0;
	
	// left <= right가 되면 무한 재귀 발생
	if (left < right) {
		middle = (left + right) / 2;
		merge(arr, left, middle);
		merge(arr, middle + 1, right);
		sort(arr, left, middle, right);
	}
}

int main(void) {
	int N = 0;

	cin >> N; 

	for (int i = 0; i < N; i++) {
		cin >> name_arr[i];
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	merge(arr, 0, N - 1);
	
	// 이름만 출력
	for (int i = 0; i < N; i++) {
		cout << name_arr[i] << "\n";
	}
	
	return 0;
}