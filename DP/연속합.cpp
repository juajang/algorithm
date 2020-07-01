#include <iostream>
using namespace std;

int N;
int arr[100000], cache[100000];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cache[0] = arr[0];
	int ans = arr[0];
	for (int i = 1; i < N; i++) {
		cache[i] = max(arr[i], arr[i] + cache[i - 1]);
		if (cache[i] > ans) ans = cache[i];
	}
	cout << ans << "\n";
	return 0;
}