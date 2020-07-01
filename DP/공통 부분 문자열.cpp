#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string str1, str2;
int cache[2][4000][4000];
int cache2[4001][4001];
int ans = 0;

//https://jaimemin.tistory.com/484
int LCS(bool head, int i, int j) {
	if (i == -1 || j == -1) return 0;
	int& ret = cache[head][i][j];
	if (ret != -1) return ret;
	if (head == 0) { //현재 이어지는 문자열이 없는 경우 
		ret = max(LCS(false, i - 1, j), LCS(false, i, j - 1));
		if (str1[i] == str2[j]) ret = max(ret, LCS(true, i - 1, j - 1) + 1);
	}
	else {
		if (str1[i] != str2[j]) ret = 0;
		else ret = LCS(true, i - 1, j - 1) + 1;
	}
	return ret;

}
 
//https://lmcoa15.tistory.com/73
void LCS2() {
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i-1] == str2[j-1]) {
				cache2[i][j] = cache2[i - 1][j - 1] + 1;
				ans = max(ans, cache2[i][j]);
			}
		}
	}
}
int main() {
	cin >> str1 >> str2;
	memset(cache, -1, sizeof(cache));
	LCS2();
	cout << ans; 
	return 0;
}