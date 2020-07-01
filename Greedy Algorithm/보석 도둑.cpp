#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
long long ans = 0;
const int MAX = 300000;
pair<int, int> j[MAX];
priority_queue<int> pq;
int bag[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	int wt, val;
	for (int i = 0; i < N; i++) {
		cin >> j[i].first >> j[i].second;
	}
	sort(j, j + N);
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(bag, bag + K);
	int idx = 0;
	for (int i = 0; i < K; i++) {
		while (j[idx].first <= bag[i] && idx < N) {
			pq.push(j[idx++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
	return 0;
}