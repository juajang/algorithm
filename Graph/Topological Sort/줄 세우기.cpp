#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M; 
vector<int> G[32001];
int indegree[32001];
queue<int> searchQ;
queue<int> res;

int main() {
	cin >> N >> M; 
	int a, b; 
	for (int i = 0; i < M; i++) {
		cin >> a >> b; 
		G[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) searchQ.push(i);
	}
	while (!searchQ.empty()) {
		int n = searchQ.front();
		searchQ.pop();
		res.push(n);
		for (int i = 0; i < G[n].size(); i++) {
			int next = G[n][i];
			indegree[next]--;
			if (indegree[next] == 0) searchQ.push(next);
		}
	}
	while (!res.empty()) {
		int n = res.front();
		res.pop();
		cout << n << " ";
	}
	return 0;
}