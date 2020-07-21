#include <iostream>
using namespace std;

typedef long long ll;
const int MAX = 10000;
ll N, M, answer, ride[MAX];

//binary search: time(분)안에 N명의 아이들이 놀이기구에 탑승할 수 있는가?
bool isPossible(ll time) {
	ll sum = M;
	for (int i = 0; i < M; i++) {
		sum += time / ride[i];
	}
	return sum >= N;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ride[i];
	}

	//놀이기구 수보다 아이들 수가 더 적은 경우 
	if (N <= M) {
		answer = N;
	}
	else {
		ll left = 1, right = N * 30, mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (isPossible(mid)) right = mid - 1;
			else left = mid + 1;
		}

		ll mm = left;
		//mm-1 분까지 각 놀이기구가 태운 아이들의 수 빼주기
		N -= M;
		for (int i = 0; i < M; i++) {
			N -= (mm - 1) / ride[i];
		}

		//mm분째에서 마지막 아이가 탄 놀이기구 
		for (int i = 0; i < M; i++) {
			if (mm % ride[i] == 0) {
				N--;
				if (N == 0) {
					answer = i + 1;
					break;
				}
			}
		}
	}
	
	cout << answer;
	return 0;
}