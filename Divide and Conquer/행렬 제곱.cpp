#include <iostream>
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<int>> arr(5, vector<int>(5));

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
	vector<vector<int>> tmp(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum += a[i][k] * b[k][j];
			}
			tmp[i][j] = (tmp[i][j] + sum) % 1000;
		}
	}
	return tmp;
}

vector<vector<int>> power(long long n) {
	vector<vector<int>> a(N, vector<int>(N));
	if (n == 1) return arr;
	else if (n % 2 == 0) {
		a = power(n / 2);
		a = multiply(a, a);
	}
	else { 
		a = power(n - 1);
		a = multiply(a, arr);
	}
	return a;
}

int main() {
	cin >> N >> B;
	vector<vector<int>> ans(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	ans = power(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (ans[i][j] % 1000) << " ";
		}
		cout << "\n";
	}
	return 0;
}