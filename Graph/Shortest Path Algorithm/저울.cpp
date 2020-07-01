#include <iostream>
using namespace std;

int N, M;
int w[101][101];

int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		w[a][b] = 1;
		w[b][a] = 1;
	}
	for (int via = 1; via <= N; via++) {
		for (int from = 1; from <= N; from++) {
			if (w[from][via] == 0) continue; //경로가 없는 경우 
			for (int to = 1; to <= N; to++) {
				if (w[via][to] == 0 || from == to) continue;
				if (w[from][to] == 0 || w[from][to] > w[from][via] + w[via][to]) {
					w[from][to] = w[from][via] + w[via][to];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (w[i][j]) sum++;
		}
		cout << sum << "\n";
	}
	return 0;
}