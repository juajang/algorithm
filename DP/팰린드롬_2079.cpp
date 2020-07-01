#include <iostream>
using namespace std;

string str;
int cache[2000][2000], res[2000];

int main() {
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		cache[i][i] = 1;
	}
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1]) cache[i][i + 1] = 1;
	}
	for (int i = 2; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (str[j] == str[j + i] && cache[j + 1][j + i - 1]) {
				cache[j][j + i] = 1;
			}
		}
	}
	res[0] = 1;
	for (int i = 1; i < len; i++) {
		res[i] = len;
		for (int j = 0; j <= i; j++) {
			if (cache[j][i]) {
				if (res[i] > res[j - 1] + 1) res[i] = res[j - 1] + 1;
			}
		}
	}
	cout << res[len - 1] << "\n";
	return 0;
}