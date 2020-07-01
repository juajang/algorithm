#include <iostream>
using namespace std;

typedef long long ll;
int N, M;
ll T[100000];

bool possible(ll time) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += time / T[i];
	}
	return sum >= M;
}

int main() {
	cin >> N >> M;
	ll MAX = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		if (MAX < T[i]) MAX = T[i];
	}
	ll left = 0, right = MAX * M;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (possible(mid)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left << "\n";
	return 0;
}