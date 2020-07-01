#include <iostream>
using namespace std;

int N, n;
int min=1000000, max=2; 

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (min > n) min = n;
		if (max < n) max = n;
	}
	cout << min * max;
	return 0;
}