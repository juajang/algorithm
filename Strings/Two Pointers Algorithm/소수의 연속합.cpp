#include <iostream>
using namespace std;

int N, num[4000000];

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		num[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (num[i] == 0) continue; //이미 체크된 수는 확인 X
		for (int j = i + i; j <= N; j += i) {
			num[j] = 0;
		}
	}
	int ans = 0, sum = 0, lo = 2, hi = 2;
	while (true) {
		if (sum >= N) {
			sum -= num[lo++];
			while (num[lo] == 0) sum -= num[lo++];
		}
		else if (hi == N + 1) break;
		else if (sum < N){
			sum += num[hi++];
		}
		if (sum == N) ans++;
	}
	cout << ans << "\n";
	return 0;
}