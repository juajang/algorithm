#include <iostream>
using namespace std;

int N, ans = 0;
int arr[10001], cache[10001];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N; 
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cache[0] = 0;
	cache[1] = arr[1];
	cache[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++) {
		//현재 잔을 마시는 경우 
		cache[i] = arr[i] + max(arr[i - 1] + cache[i - 3], cache[i - 2]);
		//현재 잔을 마시지 않는 경우 
		cache[i] = max(cache[i], cache[i - 1]);
		ans = max(ans, cache[i]);
	}
	ans = max(ans, cache[2]);
	cout << ans;
	return 0; 
}