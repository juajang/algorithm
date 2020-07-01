#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

const int INF = 0x3f3f3f;
int N, M, S, D, U, V, P;
int graph[500][500], dist[500], dist2[500];

typedef pair<int, int> p;
struct compare {
	bool operator()(p a, p b) {
		return a.second > b.second;
	}
};
priority_queue<p, vector<p>, compare> pq;
queue<int> q;

void Dijkstra(int dist[]) {
	dist[S] = 0;
	pq.push({ S, 0 });
	while (!pq.empty()) {
		int v = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[v] < cost) continue;
		for (int i = 0; i < N; i++) {
			if (graph[v][i] <= 0) continue;
			int adjCost = dist[v] + graph[v][i];
			if (adjCost <= dist[i]) {
				dist[i] = adjCost;
				pq.push({ i,adjCost });
			}
		}
	}
}

void eraseEdge() {
	q.push(D);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (graph[i][v] > 0 && dist[v] == dist[i] + graph[i][v]) {
				graph[i][v] = -1;
				q.push(i);
			}
		}
	}
 }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (true) {
		cin >> N >> M;
		memset(graph, 0, sizeof(graph));
		if (N == 0 && M == 0) break;
		cin >> S >> D; 
		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			graph[U][V] = P;
		}
		for (int i = 0; i < N; i++) {
			dist[i] = INF;
			dist2[i] = INF;
		}
		Dijkstra(dist);
		eraseEdge();
		Dijkstra(dist2);
		if (dist2[D] != INF) cout << dist2[D] << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}