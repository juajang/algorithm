#include <iostream>
using namespace std;

int N;
int card[1001], cache[1001];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}
	cache[0] = 0;
	for (int i = 1; i <= N; i++) { //각각의 카드 팩에 대해서 
		for (int j = i; j <= N; j++) { //구매하려는 카드 개수에 따른 금액의 최댓값 갱신  
			cache[j] = max(cache[j], cache[j - i] + card[i]);
		}
	}
	cout << cache[N];
	return 0;
}