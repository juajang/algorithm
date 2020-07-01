#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, sum, colorSum[200000], res[200000];

struct Ball {
	int size, color, idx;
}ball[200000];

bool COMP(const Ball &a, const Ball &b) { return a.size < b.size; }

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ball[i].color >> ball[i].size;
		ball[i].idx = i;
	}
	sort(ball, ball + N, COMP);
	for (int i = 0, j = 0; i < N; i++) {
		for (; ball[i].size > ball[j].size; j++) {
			sum += ball[j].size;
			colorSum[ball[j].color] += ball[j].size;
		}
		res[ball[i].idx] = sum - colorSum[ball[i].color];
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}