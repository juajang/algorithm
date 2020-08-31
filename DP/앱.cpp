#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int memory[100], cost[100], cache[10010];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}
	
	int total = 0;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		total += cost[i];
	}
	
	//cache[i]: cost가 i인 경우 확보할 수 있는 최대 메모리

	//각각의 앱에 대해서 업데이트
	for (int i = 0; i < N; i++) {
		//i번째 앱을 비활성화 하고서도 남은 cost가 있을 때 업데이트 (j >= cost[i])
		for (int j = total; j >= cost[i]; j--) {
			//i번째 앱을 활성화 했을 때, i번째 앱을 비활성화하고 메모리를 확보했을 때 비교
			cache[j] = max(cache[j], cache[j - cost[i]] + memory[i]);
		}
	}

	int ans = 0;
	while (ans < total && cache[ans] < M) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}