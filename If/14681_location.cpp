#include <iostream>
using namespace std;

int find_four(int X, int Y) {
	// x좌표, y좌표 모두 양수, 음수 가정 
	int location = (X > 0 ? (Y > 0 ? 1 : 4) : (Y > 0 ? 2 : 3));
	
	return location;
}

int main(void) {
	int x = 0, y = 0; // initialize

	cin >> x >> y; 
	
	cout << find_four(x, y);

	return 0;
}

