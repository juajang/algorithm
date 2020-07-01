#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x7FFFFFFF;
int N, M, X;

struct graph {
	int vertex;
	int cost;
};
struct compare {
	bool operator()(graph g1, graph g2) {
		return g1.cost > g2.cost;
	}
};

vector<graph> vill[1001];
priority_queue<graph,vector<graph>,compare> pq;

int Dijkstra(int start, int fin) {
	vector<int> result(N + 1, INF);
	result[start] = 0;
	pq.push(graph{ start, 0 });
	while (!pq.empty()) {
		int v = pq.top().vertex;
		int cost = pq.top().cost;
		pq.pop();
		if (result[v] < cost) continue;
		for (int i = 0; i < vill[v].size(); i++) {
			int adjV = vill[v][i].vertex;
			int adjCost = vill[v][i].cost + result[v];
			if (result[adjV] > adjCost) {
				result[adjV] = adjCost;
				pq.push(graph{ adjV, adjCost });
			}
		}
	}
	return result[fin];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> X;
	int u, v, w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		vill[u].push_back(graph{ v,w });
	}
	
	int max = 0;
	for (int i = 1; i <= N; i++) {
		int res = Dijkstra(X, i) + Dijkstra(i, X);
		if (max < res) max = res;
	}
	cout << max;
	return 0;
}