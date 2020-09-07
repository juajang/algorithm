#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 20010;
const int INF = 2147483647;

int N;
ll A[MAX], B[MAX], C[MAX];


ll countNum(ll num) {
	ll result = 0;
	for (int i = 0; i < N; i++) {
		if (num >= A[i]) {
			result += (min(C[i], num) - A[i]) / B[i] + 1;
		}
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> C[i] >> B[i];
	}

	ll left = 1, right = INF;
	while (left < right) {
		ll mid = (left + right) / 2;
		if (countNum(mid) % 2) {
			right = mid;
		}
		else left = mid + 1;
	}

	if (left == INF) {
		cout << "NOTHING" << endl;
	}
	else {
		int ans = countNum(left) - countNum(left - 1);
		cout << left << " " << ans << endl;
	}

	return 0;
}
