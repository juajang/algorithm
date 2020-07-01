#include <iostream>
using namespace std;

int N, arr[20][20], start[10], link[10];
int ans = 0x3f3f3f;

//중복없이 서로 다른 숫자를 N개 중에 N/2개 뽑기 
void dfs(int cnt, int idx) {
	if (cnt == N/2) {
		int idx = 0;
		//스타트 팀에 없으면 링크팀
		for (int i = 0; i < N; i++) {
			bool check = true;
			for (int j = 0; j < N / 2; j++) {
				if (start[j] == i) {
					check = false;
					break;
				}
			}
			if (check) link[idx++] = i;
		}
		int sumStart = 0, sumLink = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N / 2; j++) {
				int a = start[i];
				int b = start[j];
				sumStart += arr[a][b] + arr[b][a];
			}
		}
		for (int i = 0; i < N / 2; i++) {
			for (int j = i; j < N / 2; j++) {
				int a = link[i];
				int b = link[j];
				sumLink += arr[a][b] + arr[b][a];
			}
		}
		int diff = abs(sumStart - sumLink);
		if (diff < ans) ans = diff;
		return;
	}
	for (int i = idx; i < N; i++) {
		start[cnt] = i;
		dfs(cnt + 1, i + 1);
	}
}

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[j][i];
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}