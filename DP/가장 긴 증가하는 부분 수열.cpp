#include <iostream>
using namespace std;

int N, ans = 0;
int A[1000], cache[1000];

int max(int a, int b) { return a > b ? a : b; }
int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cache[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				cache[i] = max(cache[i], cache[j] + 1);
			}
		}
		ans = max(cache[i], ans);
	}
	cout << ans;
	return 0;
}