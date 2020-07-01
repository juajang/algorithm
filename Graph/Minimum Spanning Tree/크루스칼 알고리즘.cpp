#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
int parent[10001];

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
	cin >> V >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		G.push_back(graph{ a,b,c });
	}
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	sort(G.begin(), G.begin() + E);
	int sum = 0;
	for (int i = 0; i < G.size(); i++) {
		int from = G[i].from;
		int to = G[i].to;
		if (find(from) != find(to)) {
			merge(from, to);
			sum += G[i].cost;
		}
	}
	cout << sum;
	return 0;
}