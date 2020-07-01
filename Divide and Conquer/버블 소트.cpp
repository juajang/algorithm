#include <iostream>
using namespace std;

int N, arr[500000], arr2[500000];
long long ans = 0;

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) arr2[k++] = arr[i++];
		else {
			arr2[k++] = arr[j++];
			ans += (mid - i) + 1;
		}
	}
	while (i <= mid) arr2[k++] = arr[i++];
	while (j <= right) arr2[k++] = arr[j++];
	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void partition(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	partition(0, N - 1);
	cout << ans << "\n";
	return 0;
}