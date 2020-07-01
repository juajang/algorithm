#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[101][101];

int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (graph[a][b] == 0) graph[a][b] = c;
		else graph[a][b] = min(graph[a][b], c);
 	}

	for (int via = 1; via <= n; via++) {
		for (int from = 1; from <= n; from++) {
			if (graph[from][via] == 0) continue; //경로가 없는 경우 
			for (int to = 1; to <= n; to++) {
				if (graph[via][to] == 0 || from == to) continue;
				if (graph[from][to] == 0 || graph[from][to] > graph[from][via] + graph[via][to]) {
					graph[from][to] = graph[from][via] + graph[via][to];
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << graph[i][j] << " ";
 		}
		cout << "\n";
	}
	return 0;
}