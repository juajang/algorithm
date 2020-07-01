#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int T, n, m, t, s, g, h, a, b, d, x, distGH;
const int INF = 0x3f3f3f;
int distS[2001], distG[2001], distH[2001], G[2001][2001];

struct graph {
	int v; int cost;
};
struct compare {
	bool operator()(graph a, graph b) {
		return a.cost > b.cost;
	}
};

vector<int> dest; //목적지 후보
priority_queue<graph, vector<graph>, compare> pq;

void Dijkstra(int start, int dist[]) {
	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		int v = pq.top().v;
		int cost = pq.top().cost;
		pq.pop();
		if (dist[v] < cost) continue;
		for (int adj = 1; adj <= n; adj++) {
			if (G[v][adj] == 0) continue;
			int adjCost = dist[v] + G[v][adj];
			if (adjCost <= dist[adj]) {
				dist[adj] = adjCost;
				pq.push({ adj, adjCost });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		dest.clear();
		memset(G, 0, sizeof(G));
		cin >> n >> m >> t; 
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			G[a][b] = d;
			G[b][a] = d;
			if ((a == g && b == h) || (a == h && b == g)) distGH = d;
		}
		for (int i = 0; i < t; i++) {
			cin >> x;
			dest.push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			distS[i] = INF;
			distG[i] = INF;
			distH[i] = INF;
		}
		Dijkstra(s, distS);
		Dijkstra(g, distG);
		Dijkstra(h, distH);
		sort(dest.begin(), dest.end());
		for (int i = 0; i < dest.size(); i++) {
			int d = dest[i];
			if (distS[d] == distS[g] + distGH + distH[d]
				|| distS[d] == distS[h] + distGH + distG[d]) {
				cout << d << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}