#include <iostream>
#include <queue>
using namespace std;

int N, K;
int ans = 0;
bool visited[100001];

int bfs() {
	queue<int> q;
	q.push(N);
	while(true){
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			if (x == K) return ans;
			if (x > 0 && !visited[x - 1]) {
				q.push(x - 1);
				visited[x - 1] = true;
			}
			if (x < 100000 && !visited[x + 1]) {
				q.push(x + 1);
				visited[x + 1] = true;
			}
			if (x * 2 < 100000 && !visited[x * 2]) {
				q.push(x * 2);
				visited[x * 2] == 1;
			}
			ans++;
		}
	}
}
int main() {
	cin >> N >> K;
	cout << bfs();
	return 0;
}