#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, A[1001], B[1001];
vector<int> sumA, sumB;

int main() {
	cin >> T >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		int sum = A[i];
		sumA.push_back(sum);
		for (int j = i + 1; j <= N; j++) {
			sum += A[j];
			sumA.push_back(sum);
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
	for (int i = 1; i <= M; i++) {
		int sum = B[i];
		sumB.push_back(sum);
		for (int j = i + 1; j <= M; j++) {
			sum += B[j];
			sumB.push_back(sum);
		}
	}
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	int lo = 0, hi = sumB.size() - 1;
	long long ans = 0;
	while (true) {
		if (lo >= sumA.size() || hi < 0) break;
		else if (sumA[lo] + sumB[hi] > T) hi--;
		else if (sumA[lo] + sumB[hi] < T) lo++;
		else if (sumA[lo] + sumB[hi] == T) { //경우의 수 세기 
			long long int cnt1 = 1;
			long long int cnt2 = 1;
			while (lo + 1 <= sumA.size() - 1 && sumA[lo] == sumA[lo + 1]){
				lo++;
				cnt1++;
			}
			while (hi - 1 >= 0 && sumB[hi] == sumB[hi - 1])
			{
				hi--;
				cnt2++;
			}
			ans += cnt1 * cnt2;
			hi--;
		}
	}
	cout << ans << "\n";
	return 0;
}