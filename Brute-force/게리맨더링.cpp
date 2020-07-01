#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N, n, v, M, ppl[11], area[11];
int ans = 1000;
vector<int> graph[11];
queue<int> q;

void isConnected(int here, vector<bool> &visited, int num) {
	q.push(here);
	while (!q.empty()) {
		int here = q.front();
		visited[here] = true;
		q.pop();
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (num == 1 && !area[next]) continue;
			if (num == 2 && area[next]) continue;
			if (!visited[next]) {
				q.push(next);
			}
		}
	}
}


void backtracking(int idx, int cnt) {
	if (cnt == M) {
		vector<bool> visited(11, 0), visited2(11, 0);
		vector<int> subG1, subG2;
		bool chk = 0, chk2 = 0;
		for (int i = 1; i <= N; i++) {
			if (chk == 1 && chk2 == 1) break;
			if (area[i] && !chk) {
				isConnected(i, visited, 1);
				chk = true;
			}
			else if (!area[i] & !chk2) {
				isConnected(i, visited2, 2);
				chk2 = true;
			}
		}
		int sum1 = 0, sum2 = 0;
		bool connect = true;
		for (int i = 1; i <= N; i++) {
			if (!connect) break;
			else if (area[i] && !visited[i]) connect = false;
			else if (area[i] && visited[i]) sum1 += ppl[i];
			else if (!area[i] && !visited2[i]) connect = false;
			else if (!area[i] && visited2[i]) sum2 += ppl[i];
		}
		if (connect) ans = min(ans, abs(sum1 - sum2));
		return;
	}
	for (int i = idx; i <= N; i++) {
		area[i] = 1;
		backtracking(i + 1, cnt + 1);
		area[i] = 0;
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ppl[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> v;
			graph[i].push_back(v);
		}
	}
	for (int i = 1; i < N; i++) {
		M = i;
		backtracking(1, 0);
	}
	cout << (ans == 1000 ? -1 : ans) << "\n";
	return 0;
}