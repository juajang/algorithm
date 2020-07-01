#include <iostream>
using namespace std;

int A, B, V, ans;

int main() {
	cin >> A >> B >> V;
	int high = V, low = 0;
	while (low <= high) {
		int mid = (high + low) / 2;
		int dist = (A - B) * (mid - 1) + A;
		if (dist >= V) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ans;
	return 0;
}