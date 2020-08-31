#include <iostream>
#include <algorithm>
using namespace std;

int N, books[200000], LIS[200000];

// LIS(Longest Increasing Subsequence)
// target이 찾는 구간에 없는 경우 가장 마지막 위치 
// 있는 경우에는 교체되어야 할 위치(크거나 같은 첫 번재 위치) 반환 
int lowerBound(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;

		//찾고자 하는 값보다 작으면 오른쪽 범위에서 탐색한다.
		if (LIS[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> books[i];
	}

	int ans = 0;
	LIS[0] = books[0];

	for (int i = 1, j = 0; i < N; i++) {
		// 끼워넣어야 할 책의 번호가 가장 큰 경우, 그냥 넣어도 됨 
		if (LIS[j] < books[i]) {
			LIS[++j] = books[i];
		}

		// 교체되어야 할 위치 추출 
		else {
			int pos = lowerBound(0, j, books[i]);
			LIS[pos] = books[i];
			ans++; //교체 횟수 
		}
	}

	cout << ans << endl;
	return 0;
}