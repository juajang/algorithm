#include <iostream>
#include <vector>
using namespace std;

int T, n;
vector<int> student;
vector<int> first_student;
vector<int> visited;

int dfs(int start, int current, int cnt) {
	if (visited[current]) {
		if (first_student[current] != start) return 0;
		return cnt - visited[current];
	}
	first_student[current] = start;
	visited[current] = cnt;
	return dfs(start, student[current], cnt + 1);
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		student = vector<int>(n + 1, 0);
		first_student = vector<int>(n + 1, 0);
		visited = vector<int>(n + 1, 0);
		for (int j = 1; j <= n; j++) {
			cin >> student[j];
		}
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) ans+= dfs(j,j,1);
		}
		cout << n - ans << "\n";
	}
	return 0;
}