#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, d, p, MAX_DAY = 0;
vector<pair<int, int>> v(10000);
priority_queue<int> PQ;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v[i] = { -d, p };
		MAX_DAY = max(d, MAX_DAY);
	}

	sort(v.begin(), v.end());

	int ans = 0, j = 0;
	for(int i = MAX_DAY; i >= 1; i--) {
		while (j < v.size() && i <= -v[j].first) {
			PQ.push(v[j].second);
			j++;
		}
		if (!PQ.empty()) {
			ans += PQ.top();
			PQ.pop();
		}
	}

	cout << ans << endl;
	return 0;
}