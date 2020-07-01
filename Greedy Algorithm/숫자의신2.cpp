#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int K, N;
priority_queue<long long, vector<long long>, less<long long>> pq;
priority_queue<long long, vector<long long>, less<long long>> num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		pq.push(n);
	}
	long long max = pq.top();
	for (int i = 0; i < K; i++) {
		long long n = pq.top();
		pq.pop();
		num.push(n);
	}
	while (N > K) {
		num.push(max);
		N--;
	}
	while (!num.empty()) {
		long long n = pq.top();
		cout << n;
		pq.pop();
	}
	return 0;
}