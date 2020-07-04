#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<int>> A(11, vector<int>(11,5));
vector<vector<int>> food(11, vector<int>(11));
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

vector<int> tree[11][11];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> food[i][j];
		}
	}

	int y, x, age;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> age;
		tree[x][y].push_back(age);
	}

	while (K--) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tree[i][j].size() == 0) continue;
				vector<int> tmp;
				int dead_tree = 0;
				sort(tree[i][j].begin(), tree[i][j].end());
				for (int k = 0; k < tree[i][j].size(); k++) {
					int age = tree[i][j][k];
					if (A[i][j] >= age) {
						A[i][j] -= age;
						tmp.push_back({ age + 1 });
					}
					else {
						dead_tree += age / 2;
					}
				}
				tree[i][j].clear();
				for (int k = 0; k < tmp.size(); k++) {
					tree[i][j].push_back(tmp[k]);
				}
				A[i][j] += dead_tree;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tree[i][j].size() == 0) continue;
				for (int k = 0; k < tree[i][j].size(); k++) {
					if (tree[i][j][k] % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							int nx = i + dir[d][0];
							int ny = j + dir[d][1];
							if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				A[i][j] += food[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
	return 0;
}

