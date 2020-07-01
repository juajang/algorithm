#include <iostream>
#include <vector>
using namespace std;

int pan[9][9];
typedef pair<int, int> p;
vector<p> blank;

void sudoku(int idx, int pan[9][9]) {
	int arr[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arr[i][j] = pan[i][j];
		}
	}
	if (idx == blank.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << pan[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int y = blank[idx].first;
	int x = blank[idx].second;

	bool num[10] = {};
	for (int i = 0; i < 10; i++) {
		num[i] = true;
	}
	for (int i = 0; i < 9; i++) {
		num[arr[y][i]] = false;
		num[arr[i][x]] = false;
	}
	int startY = (y / 3) * 3;
	int startX = (x / 3) * 3;
	for (int i = startY; i < startY + 3; i++) {
		for (int j = startX; j < startX + 3; j++) {
			num[arr[i][j]] = false;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (num[i]) {
			arr[y][x] = i;
			sudoku(idx + 1, arr);
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 0) blank.push_back({ i,j });
		}
	}
	sudoku(0, pan);
	return 0;
}