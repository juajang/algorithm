#include <iostream>
#include <functional>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

const int INF = 0x7FFFFFFF;
int V, E, K;
int dist[20001];

struct compare {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.second > b.second;
	}
};
vector<pair<int, int>> graph[20001]; //vertex, weight
priority_queue<pair<int,int>,vector<pair<int, int>>,compare> pq; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	pq.push(make_pair(K, 0));
	dist[K] = 0;
	while (!pq.empty()) {
		int idx = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[idx] < cost) continue;
		for (int i = 0; i < graph[idx].size(); i++) {
			int adjV = graph[idx][i].first;
			int adjCost = graph[idx][i].second + dist[idx];
			if (dist[adjV] > adjCost) {
				dist[adjV] = adjCost;
				pq.push(make_pair(adjV, adjCost));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}