#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; 
int parent[100001];

struct graph {
	int from, to;
	int cost;
};
bool operator<(const graph& g1, const graph& g2) {
	return g1.cost < g2.cost;
}
vector<graph> G;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[x] = y;
	return;
}

int main() {
	cin >> N >> M;
	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		G.push_back(graph{ A,B,C });
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	sort(G.begin(), G.begin() + M);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < G.size() && cnt < N-2; i++) {
		int from = G[i].from;
		int to = G[i].to;
		if (find(from) != find(to)) {
			merge(from, to);
			cnt++;
			sum += G[i].cost;
		}
	}
	cout << sum;
	return 0;
}