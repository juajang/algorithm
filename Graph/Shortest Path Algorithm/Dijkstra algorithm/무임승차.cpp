#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

const double INF = 0x3f3f3f;
int T, n, m, start, fin, s, p, y, a, b, c;
double d, dist[201];

struct train {
	int v; double cost; int pb;
};
struct compare {
	bool operator()(train a, train b) {
		return a.cost > b.cost;
	}
};

priority_queue<train, vector<train>, compare> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		vector<train> graph[201];
		cin >> n >> m >> start >> fin >> s >> p >> y; 
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c >> d;
			graph[a].push_back({ b,d,c });
			graph[b].push_back({ a,d,c });
		}
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}
		dist[start] = 0; 
		pq.push({ start, 0 });
		while (!pq.empty()) {
			int v = pq.top().v;
			double costHere = pq.top().cost;
			pq.pop();
			if (dist[v] < costHere) continue;
			for (int i = 0; i < graph[v].size(); i++) {
				int adj = graph[v][i].v;
				double adjPb = graph[v][i].pb / 100.0;
				double adjCost = graph[v][i].cost;
				double MIN = min(s + adjCost * p, adjPb * (y + adjCost * p)) + costHere;
				if (MIN < dist[adj]) {
					dist[adj] = MIN;
					pq.push({ v,MIN });
				}
			}
		}
		cout << dist[fin] << "\n";
		dist[fin] = roundf(dist[fin] * 100) / 100;
		cout << dist[fin] << "\n";
	}
	return 0;
}