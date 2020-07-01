#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		int p = Find(parent[x]);
		parent[x] = p; 
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	bool req;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> req >> a >> b;
		if (req == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}