#include <iostream>
#include <string.h>
using namespace std;

#define INF 1000001;
int N;
int cache[1000001];

int min(int a, int b) { return a > b ? b : a; }

int calc(int n) {
	int& ret = cache[n];
	if (n == 1) return 0;
	if (ret != -1) return ret;
	ret = calc(n - 1)+1;
	if (n % 3 == 0) ret = min(calc(n / 3)+1, ret);
	if (n % 2 == 0) ret = min(calc(n / 2)+1, ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N;
	memset(cache, -1, sizeof(cache));
	cout << calc(N);
	return 0; 
}