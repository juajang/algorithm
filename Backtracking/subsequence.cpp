#include <iostream>
using namespace std;

int num[20];
bool select[20];
int N, M, S;
int ans = 0, sum = 0;

void sumSub() {
	for (int i = 0; i < N; i++) {
		if (select[i]) sum += num[i];
	}
	if (sum == S) ans++;
	sum = 0;
}
void subsequence(int cnt, int idx) {
	if (M == cnt) {
		sumSub();
		return;
	}
	for (int i = idx; i < N; i++) {
		if (select[i]) continue;
		select[i] = true;
		subsequence(cnt + 1, i);
		select[i] = false;
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (M = 1; M <= N; M++) {
		subsequence(0, 0);
	}
	cout << ans;
	return 0;
}