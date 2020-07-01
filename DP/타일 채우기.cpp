#include <iostream>
#include <string.h>
using namespace std;

int T, N;
int cache[101][4];

int tile(int width, int state) {
	//(0000)인 경우 외에는 잘못된 경우
	if (width == 0) return state == 0;
	int& ret = cache[width][state];
	if (ret != -1) return ret;
	if (state == 0) {
		ret = tile(width - 1, 0) + tile(width - 2, 0) + 2 * tile(width - 1, 1) + tile(width - 1, 3);
	}
	else if (state == 1) {
		ret = tile(width - 1, 1) + tile(width - 1, 0);
	}
	else if (state == 2) {
		ret = tile(width - 1, 3);
	}
	else if (state == 3) {
		ret = tile(width - 1, 0) + tile(width - 1, 2);
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> T;
	while (T--) {
		cin >> N;
		cout << tile(N, 0) << "\n";
	}
	return 0;
}