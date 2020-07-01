#include <iostream>
using namespace std;

int N;
const int MAX = 100000;
long long rd[MAX];
long long price[MAX];
long long ans[MAX];

int main() {
	cin >> N; 
	for (int i = 0; i < N - 1; i++) {
		cin >> rd[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
	ans[0] = price[0] * price[0];
	long long min = price[0];
	for (int i = 1; i < N; i++) {
		if (price[i] < min) {
			min = price[i];
		}
		ans[i] = ans[i - 1] + min * price[i];
	}
	cout << ans[N - 1];
	return 0;
}