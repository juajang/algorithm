#include <iostream>
#include <string.h>
using namespace std;

int k = -1;
int N = 6;
int num[13];
bool select[13];

void print() {
	for (int i = 0; i < k; i++) {
		if (select[i]) cout << num[i] << " ";
	}
	cout << "\n";
}

void lotto(int cnt, int idx) {
	if (N == cnt) {
		print();
		return;
	}
	for (int i = idx; i < k; i++) {
		if (select[i]) continue;
		select[i] = true;
		lotto(cnt + 1, i);
		select[i] = false;
	}
}

int main() {
	cin >> k;
	while (k != 0) {
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		lotto(0, 0);
		cout << "\n";
		cin >> k;
	}
	return 0;
}