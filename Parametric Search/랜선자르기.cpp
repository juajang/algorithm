#include <iostream>
#include <climits>
using namespace std;

long long K, N; 
long long ans = 0;
long long lan[10000];

int main() {
	cin >> K >> N;
	long long left = 1, right = 0;
	for (int i = 0; i < K; i++) {
		cin >> lan[i];
		if (right < lan[i]) right = lan[i];
	}
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++) {
			sum += (lan[i] / mid);
		}
		if (sum >= N) {
			if (mid > ans) ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}