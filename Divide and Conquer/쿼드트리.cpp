#include <iostream>
using namespace std;

int N; 
int arr[64][64];

void quadTree(int y, int x, int size) {
	bool check = true;
	int cur = arr[y][x];
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (cur != arr[i][j]) check = false;
		}
	}
	if (check) cout << cur;
	else {
		cout << "(";
		quadTree(y, x, size / 2);
		quadTree(y, x + size / 2, size / 2);
		quadTree(y + size / 2, x, size / 2);
		quadTree(y + size / 2, x + size / 2, size / 2);
		cout << ")";
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	quadTree(0, 0, N);
	return 0;
}