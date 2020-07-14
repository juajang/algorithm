#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 110;
int N, ans = 0;
int node[MAX];
bool visited[MAX];
vector<int> answer;

void dfs(int start, int now) {
	if (visited[now]) {
		if (start == now) answer.push_back(now);
		return;
	}
	visited[now] = true;
	dfs(start, node[now]);	
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> node[i];
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}