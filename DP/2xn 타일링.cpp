#include <iostream>
#include <string.h>
using namespace std;

int n;
int cache[1001];
//cache - 길이가 m 일때 채우는 방법의 수 

int rec(int m) {
	if (m == 0) return 1;
	else if (m < 0) return 0;
	int& let = cache[m];
	if (let != -1) return let;
	let = (rec(m - 1) + rec(m - 2)) % 10007;
	return let;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << rec(n) << "\n";
	return 0;
}