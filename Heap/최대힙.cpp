#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x == 0 && pq.empty()) cout << "0" << "\n";
		else if (x == 0) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		else if (x > 0) pq.push(x);
	}
	return 0;
}