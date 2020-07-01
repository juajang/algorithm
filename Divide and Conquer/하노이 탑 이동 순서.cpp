#include <iostream>
#include <math.h>
using namespace std;

int N;

void Hanoi(int n, int from, int to) {
	if (n == 0) return;
	Hanoi(n - 1, from, 6 - from - to); //1~n-1개의 탑을 2번으로 
	cout << from << " " << to << "\n"; //마지막에 깔려있는걸 3번으로
	Hanoi(n - 1, 6 - from - to, to); //n-1개를 3번으로
}

int main() {
	cin >> N;
	int ans = (int)pow(2, N) - 1;
	cout << ans << "\n";
	Hanoi(N, 1, 3);
	return 0;
}