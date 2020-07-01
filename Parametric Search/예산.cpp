#include <iostream>
using namespace std;

int N;
int bg[10000];
long long M;
int ans = 0;

int main() {
	cin >> N;
	int left = 0, right = 0;
	for (int i = 0; i < N; i++) {
		cin >> bg[i];
		if (right < bg[i]) right = bg[i];
	}
	cin >> M;
	long long max = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0; 
		for (int i = 0; i < N; i++) {
			if (bg[i] > mid) sum += mid;
			else sum += bg[i];
		}
		if (sum <= M) { //예산 안에서 배정한 경우 
			if (sum > max) {
				max = sum;
				ans = mid;
			}
			left = mid + 1;
			//cout << mid << " " << sum << "\n";
		}
		else { //예산 초과 
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}