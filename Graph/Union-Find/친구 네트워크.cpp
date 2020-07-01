#include <iostream>
#include <string>
#include <map>
using namespace std;

int parent[100001];
int level[100001];
int cnt[100001];
int T, F;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

int cnt_merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return cnt[x];
	if (level[x] > level[y]) swap(x, y);
	parent[x] = y;
	cnt[y] += cnt[x];
	if (level[x] == level[y]) ++level[y];
	return cnt[y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> F;
		map <string, int> frmap;
		int idx = 1;
		for (int i = 1; i <= 100000; i++) {
			parent[i] = i;
			level[i] = 1;
			cnt[i] = 1;
		}
		for(int i=0; i<F; i++){
			string f1, f2;
			cin >> f1 >> f2;
			if (frmap.count(f1) == 0) frmap[f1] = idx++;
			if (frmap.count(f2) == 0) frmap[f2] = idx++;
			int cnt = cnt_merge(frmap[f1], frmap[f2]);
			cout << cnt << "\n";
		}
	}
	return 0;
}