#include <vector>
#include <iostream>
using namespace std;

long long Sum(vector<int> &a) {
	long long IntSum = 0; // Initialize

	for (long unsigned int i = 0; i < a.size(); i++) { // Sum
		IntSum = IntSum + a[i];
	}

	return IntSum; // return
}
// 이 부분까지가 정답으로 인정됨.

int main(void) {
	int n = 0; // Initialize
	int number = 0;

	cin >> n; // input 

	vector<int> a(n); // vector's size

	for (int i = 0; i < n; i++) { // push to vector
		cin >> number;
		a.push_back(number);
	}

	cout << (long long)Sum(a); // function call
}