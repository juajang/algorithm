#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N,compare);
	int start = arr[0].second;
	int ans = 1;
	for (int i = 1; i < N; i++) {
		if (start <= arr[i].first) {
			ans++;
			start = arr[i].second;
		}
	}
	cout << ans;
	return 0;
}