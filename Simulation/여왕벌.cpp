#include <iostream>
using namespace std;

int M, day;
int larva[700][700], newLarva[700][700], growing[1400];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> M >> day;
	for (int i = 0; i < 2*M-1; i++) {
		growing[i] = 1;
	}
	while (day--) {
		int cnt, grow = 0, idx = 0;
		for (int i = 0; i < 3; i++) {
			cin >> cnt;
			for (int i = idx; i < idx + cnt; i++) {
				growing[i] += grow;
			}
			idx = idx + cnt;
			grow++;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0) {
				cout << growing[M - 1 - i] << " ";
			}
			else {
				cout << growing[M - 1 + j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}