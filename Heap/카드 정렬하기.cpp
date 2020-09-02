#include <iostream>
#include <queue>
using namespace std;

int N, C;
priority_queue<int> card;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> C;
		card.push(-C);
	}

	int ans = 0;

	while (card.size() != 1) {
		int a = -card.top();
		card.pop();
		int b = -card.top();
		card.pop();

		ans += a + b;
		card.push(-(a + b));
	}

	cout << ans << endl;
	return 0;

}