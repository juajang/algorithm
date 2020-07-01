#include <iostream>
using namespace std;

int M, ans = 1;
bool dir = 0;
int wheel[1000][3];

int main() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> wheel[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		ans = ans / wheel[i][0] * wheel[i][1];
		if (wheel[i][2]) dir = !dir;
	}
	cout << dir << " " << ans;
	return 0;
}