#include <iostream>
using namespace std;

int N, M;
int map[201][201];

int parent[201];
int level[201];
int path[1001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (level[x] > level[y]) swap(x, y);
	parent[x] = y;
	if (level[x] == level[y]) ++level[y];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
 	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j]) merge(i, j);
;		}
	}
	bool check = true;
	for (int i = 1; i <= M; i++) cin >> path[i];
	for (int i = 1; i < M; i++) {
		if (find(path[i]) != find(path[i + 1])) {
			check = false;
		}
	}
	if (check) cout << "YEs\n";
	else cout << "NO\n";
	return 0;
}
