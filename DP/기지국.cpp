#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 10010;
const int INF = 0x3f3f3f3f;
int N, x, y, cache[MAX];

int main() {
	cin >> N;
	vector<pair<int, int>> v(N + 1);
	for (int i = 1; i <= N; i++) { 
		cin >> v[i].first >> v[i].second;
		if (v[i].second < 0) {
			v[i].second *= -1;
		}
	}

	sort(v.begin() + 1, v.end());

	//cache[n]: n번째 기지국까지 지었을 때의 최솟값
	for (int i = 1; i <= N; i++) {
		cache[i] = INF;
	}
	cache[0] = 0;
	
	for (int i = 1; i <= N; i++) {
		int maxHeight = 0;
		//i번째 기지국을 지을때, 그 전의 기지국을 모두 고려 
		for (int j = i; j >= 1; j--) { 

			//j번째 기지국 ~ i번째 기지국 중 최대 높이 
			maxHeight = max(maxHeight, v[j].second);

			//정사각형 형태이므로 좌표를 커버할 수 있는 정사각형의 너비 구하기 
			int square = max(v[i].first - v[j].first, maxHeight * 2);
			cache[i] = min(cache[i], cache[j - 1] + square);
		}
	}
	
	cout << cache[N] << endl;
	return 0;
}