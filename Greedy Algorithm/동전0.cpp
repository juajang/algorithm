#include <iostream>
#include <vector>
using namespace std;

int N, K; 
int ans = 0;

int main() {
	cin >> N >> K;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int sum = K, idx = N - 1;
	while (sum != 0) {
		for (int i = idx; i >= 0; i--) {
			if (sum >= v[idx]) {
				ans += sum / v[idx];
				sum = sum % v[idx];
			}
			break;
		}
		idx = idx - 1; 
	}
	cout << ans;
	return 0; 
}