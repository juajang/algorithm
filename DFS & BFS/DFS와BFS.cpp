#include <iostream>
#include <string.h>
#include <queue>
using namespace std; 

int N, M, V; 
bool e[1001][1001];
bool visited[1001];
queue<int> q;

void bfs(int v) {
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int n = q.front();
		cout << n << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (e[n][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= N; i++) {
		if (e[v][i] && !visited[i]) dfs(i);
	}
}
int main() {
	cin >> N >> M >> V;
	int j, k;
	for (int i = 0; i < M; i++) {
		cin >> j >> k; 
		e[j][k] = true;
		e[k][j] = true;
	}
	dfs(V);
	memset(visited, false, sizeof(visited));
	cout << "\n";
	bfs(V);
	return 0;
}