#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8], s[8], check[8];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
		return;
	}
	int prev = -1;
	for (int i = 0; i < N; i++) {
		if (prev == arr[i] || check[i]) continue;
		if (cnt != 0 && s[cnt - 1] > arr[i]) continue;
		prev = arr[i];
		s[cnt] = arr[i];
		check[i] = 1;
		dfs(cnt + 1);
		check[i] = 0;
	}

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0);
	return 0;
}