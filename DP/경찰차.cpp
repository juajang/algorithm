#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, W; 
int cache[1001][1001];
vector<pair<int, int>> v;
int result[1001];

int getDist(int from, int to) {
	int x1, y1, x2, y2;
	if (from == -1) { x1 = 1; y1 = 1; }
	else if (from == -2) { x1 = N; y1 = N; }
	else { x1 = v[from].first; y1 = v[from].second; }
	x2 = v[to].first; 
	y2 = v[to].second;
	return abs(x1 - x2) + abs(y1 - y2);
}

int dp(int x, int y) {
	if (x == W || y == W) return 0;
	int& let = cache[x][y];
	if (let != -1) return let;
	int cur = max(x, y) + 1;
	int prevX = x, prevY = y;
	if (x == 0) prevX = -1;
	if (y == 0) prevY = -2;
	let = min(dp(cur, y) + getDist(prevX,cur), dp(x, cur) + getDist(prevY,cur));
	return let;
}

void solve(int x, int y) {
	if (x == W || y == W) return;
	int cur = max(x, y) + 1;
	int prevX = x, prevY = y;
	if (x == 0) prevX = -1;
	if (y == 0) prevY = -2;
	int first = dp(cur, y) + getDist(prevX, cur);
	int second = dp(x, cur) + getDist(prevY, cur);
	if (first < second) {
		result[cur] = 1;
		solve(cur, y);
	}
	else {
		result[cur] = 2;
		solve(x, cur);
	}
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> W;
	int x, y;
	v.push_back(make_pair(0,0));
	for (int i = 1; i <= W; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	cout << dp(0, 0) << "\n";
	solve(0, 0);
	for (int i = 1; i <= W; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}