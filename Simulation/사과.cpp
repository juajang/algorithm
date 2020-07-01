#include <iostream>
using namespace std;

int N, apple[100][2];
int ans = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> apple[i][j];
		}
		int idx = 1;
		while (apple[i][0] * idx <= apple[i][1]) {
			idx++;
		}
		ans += apple[i][1] - apple[i][0] * (idx-1);
	}
	cout << ans;
	return 0;
}