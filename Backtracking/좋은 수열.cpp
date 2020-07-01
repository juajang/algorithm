#include <iostream>
#include <string>
using namespace std;

int N;
string num;

void dfs(int cnt, char n) {
	if (cnt - 1 == N) {
		cout << num;
		exit(0);
	}
	num += n;
	for (int i = 1; i <= cnt / 2; i++) {
		string a = num.substr(cnt - i * 2, i);
		string b = num.substr(cnt - i, i);
		if (a == b) {
			num.erase(cnt - 1);
			return;
		}
	}
	//cout << num << "\n";
	for (int i = 1; i <= 3; i++) {
		dfs(cnt + 1, i + '0');
	}
	num.erase(cnt - 1); //현재 자리가 성립하지 않는 경우 
}

int main() {
	cin >> N;
	for (int i = 1; i <= 3; i++) {
		dfs(1, i + '0');
	}
	return 0;
}