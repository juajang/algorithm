#include <iostream>
using namespace std;

const int MAX = 300001;
typedef pair<int, int> p;

int N, Q, nxt[MAX], parent[MAX], ans[MAX], idx = 0;
bool chk[MAX];
p query[MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) parent[x] = parent[y] = 0; //사이클이 생긴 경우
	else parent[x] = y;
}

//간선을 지우는 쿼리 => 거꾸로 만들어나가는 오프라인 쿼리 이용

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> nxt[i];
		parent[i] = i;
		chk[i] = false;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> query[i].first >> query[i].second;
		if (query[i].first == 2) chk[query[i].second] = true;
	}
	//지워야 할 간선은 제외하고, 쿼리가 모두 끝났을 때의 그래프를 만든다. 
	for (int i = 1; i <= N; i++) {
		if (!chk[i] && nxt[i]) Union(i, nxt[i]); 
 	}
	for (int i = Q; i >= 1; i--) { //쿼리의 역순으로 간선을 만들어나가기 
		int v = query[i].second;
		if (query[i].first == 1) {
			ans[++idx] = Find(v);
		}
		else {
			Union(v, nxt[v]);
		}
	}
	for (int i = idx; i >= 1; i--) {
		if (!ans[i]) cout << "CIKLUS\n";
		else cout << ans[i] << "\n";
	}
	return 0;
}