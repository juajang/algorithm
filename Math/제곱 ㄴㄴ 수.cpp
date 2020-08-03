#include <iostream>
using namespace std;

typedef long long ll;
ll MIN, MAX;
ll numbers[1000010];

int main() {
	cin >> MIN >> MAX;

	//에라토스테네스의 체: 제곱수를 지워나가기 
	for (ll i = 2; i * i <= MAX; i++) {
		//지워나가기 시작할 숫자, 나누어 떨어지지 않는다면 그 다음 숫자부터 시작 
		ll x = MIN / (i * i);
		if (MIN % (i * i)) x++;

		//제곱수와 나누어 떨어지는 숫자들 체크하기 
		while (x * (i * i) <= MAX) {
			numbers[x * (i * i) - MIN] = 1;
			x++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= MAX - MIN; i++) {
		if (numbers[i] == 0) ans++;
	}
	cout << ans;
	return 0;
}