#include <iostream>
using namespace std;

int N, P[48], S[48], card[48], ans = 0;

//카드를 한 번 섞고 나면 i번째 위치에 있던 카드는 S[i]번째 위치로 이동하게 된다.
//각 카드가 어떤 플레이어에게 가야 하는지에 대한 정보는 P 

void shuffling() {
	int tmp[48];
	for (int i = 0; i < N; i++) {
		tmp[i] = card[i];
	}
	for (int i = 0; i < N; i++) {
		card[S[i]] = tmp[i];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		card[i] = P[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	bool check = true , success = false;
	while (check) {
		check = false, success = true;
		for (int i = 0; i <= N - 3; i += 3) {
			if (card[i] % 3 != 0) success = false;
			if (card[i + 1] % 3 != 1) success = false;
			if (card[i + 2] % 3 != 2) success = false;
		}
		if (success) break;
		shuffling();
		//초기와 같아지면 그만두기 
		for (int i = 0; i < N; i++) {
			if (card[i] != P[i]) check = true;
		}
		ans++;
	}
	if (!success) cout << -1;
	else cout << ans;
	return 0;
}