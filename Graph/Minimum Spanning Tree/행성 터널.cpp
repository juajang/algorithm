#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;
int N, X, Y, Z, ans, parent[100000], cnt = 0;

struct planet {
	int from; int to; int cost;
};

bool operator<(const planet& p1, const planet& p2) {
	return p1.cost < p2.cost;
}

vector<planet> graph;
p x[100000], y[100000], z[100000];

void getDist(p loc[]) {
	sort(loc, loc + N);
	for (int i = 1; i < N; i++) {
		int dist = abs(loc[i].first - loc[i - 1].first);
		graph.push_back({ loc[i].second, loc[i - 1].second, dist });
	}
}

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	parent[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y >> Z;
		x[i] = { X, i };
		y[i] = { Y, i };
		z[i] = { Z, i };
	}
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	getDist(x); getDist(y); getDist(z);
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++) {
		if (cnt == N - 1) break;
		int from = graph[i].from;
		int to = graph[i].to;
		if (Find(from) != Find(to)) { 
			Union(from, to);
			cnt++;
			ans += graph[i].cost;
		}
	}
	cout << ans;
	return 0;
}