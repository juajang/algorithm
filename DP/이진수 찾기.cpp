#include <iostream>
#include <string.h>
typedef long long ll;
using namespace std;

int N, L;
string ans = "";
ll I, cache[35][35];

// 길이가 n이고 사용된 1의 개수가 l 이하인 이진수의 개수 
ll getBinaryCount(int n, int l) {
	ll& ret = cache[n][l];

	if (ret != -1) return ret;
	if (n == 0 || l == 0) return ret = 1;

	// 1인 비트를 사용하지 않고 넘어가기 
	ret = getBinaryCount(n - 1, l);
	// 1인 비트가 남아있는 경우, 비트 사용
	if (l > 0) ret += getBinaryCount(n - 1, l - 1);

	return ret;
}

// 길이가 n이고 사용한 1인 비트의 개수가 l개일 때 i번째 이진수 찾아내기 
void findIthNumber(int n, int l, ll i) {
	if (n == 0) return;
	
	// n은 남아있지만 사용 가능한 비트가 없는 경우, 나머지는 0으로 채우기 
	if (l == 0) {
		for (int i = 0; i < n; i++) {
			ans += '0';
		}
		return;
	}

	ll pivot = getBinaryCount(n - 1, l);
	
	// 나머지 n-1개의 자리수에서도 i번째로 큰 수가 충분히 나올 수 있다.
	if (pivot >= i) {
		ans += '0';
		findIthNumber(n - 1, l, i);
	}

	// 나머지 n-1개 자리수끼리는 i번째로 큰 수를 만들 수 없다.
	else {
		ans += '1';
		findIthNumber(n - 1, l - 1, i - pivot);
	}
}

int main() {
	cin >> N >> L >> I;

	memset(cache, -1, sizeof(cache));

	findIthNumber(N, L, I);
	cout << ans << endl;

	return 0;
}