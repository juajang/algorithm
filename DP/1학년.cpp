<<<<<<< HEAD
#include <iostream>
#include <string.h>
using namespace std;

int N, numbers[100];
long long cache[100][30];

long long dfs(int idx, int sum) {
	long long& ret = cache[idx][sum];
	if (ret != -1) return ret;
	ret = 0;
	if (sum < 0 || sum > 20) return 0; 
	if (idx == N - 1) {
		if (sum == numbers[N - 1]) ret += 1;
		return ret;
	}
	ret = dfs(idx + 1, sum + numbers[idx]) + dfs(idx + 1, sum - numbers[idx]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	cout << dfs(1, numbers[0]);
	return 0;
}
=======
#include <iostream>
#include <string.h>
using namespace std;

int N, numbers[100];
long long cache[100][30];

long long dfs(int idx, int sum) {
	long long& ret = cache[idx][sum];
	if (ret != -1) return ret;
	ret = 0;
	if (sum < 0 || sum > 20) return 0; 
	if (idx == N - 1) {
		if (sum == numbers[N - 1]) ret += 1;
		return ret;
	}
	ret = dfs(idx + 1, sum + numbers[idx]) + dfs(idx + 1, sum - numbers[idx]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	cout << dfs(1, numbers[0]);
	return 0;
}
>>>>>>> 4887953ed8aca312d3cd9f7d780b3cbdaf011466
