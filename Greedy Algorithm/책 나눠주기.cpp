#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, T;
pair<int, int> student[1000];
bool visited[1000];
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int ans = 0;
		memset(student, 0, sizeof(student));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < M; i++) {
			cin >> student[i].first >> student[i].second;
		}
		sort(student, student + M, compare);
		for (int i = 0; i < M; i++) {
			for (int j=ans; j <= student[i].second; j++) {
				if (ans<N) {
					cout << "\n" << student[i].first << " " << student[i].second << "\n";
					ans++;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}