#include <iostream>
using namespace std;

int N, arr[1000], cache[1000][2];
int ans = 1;

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cache[i][0] = 1; 
		cache[i][1] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache[i][0] = max(cache[j][0] + 1, cache[i][0]);
				ans = max(ans, cache[i][0]);
			}
			else if (arr[i] < arr[j]) {
				cache[i][1] = max(cache[j][1] + 1, cache[i][1]);
				cache[i][1] = max(cache[j][0] + 1, cache[i][1]);
				ans = max(ans, cache[i][1]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}