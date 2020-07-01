#include <iostream>
#include <string.h>
using namespace std;

int n;
int tr[500][500];
int cache[500][500];
int ans = 0;
int max(int a, int b) { return a > b ? a : b; }

int dfs(int y, int x) {
	if (y == n) return 0;
	int& ret = cache[y][x];
	if (cache[y][x] != -1) return cache[y][x];
	ret = tr[y][x];
	ret += max(dfs(y + 1, x),dfs(y + 1, x + 1));
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> tr[i][j];
		}
	}
	ans = dfs(0, 0);
	cout << ans;
	return 0;
}