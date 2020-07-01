#include <iostream>
using namespace std;

long long N, M;
long long t[1000000];
int ans = 0;

int main() {
	cin >> N >> M; 
	int left = 0, right = 0;
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		if (right < t[i]) right = t[i];
	}
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0; 
		for (int i = 0; i < N; i++) {
			if (t[i] > mid) sum += t[i] - mid;
		}
		if (sum <= M) { //더 배정해도 됨 
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		else { //예산이 부족한 경우  
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}