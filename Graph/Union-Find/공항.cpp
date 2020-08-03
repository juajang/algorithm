#include <iostream>
#define MAX 100010
using namespace std;

int G, P, ans;
int plane[MAX], parent[MAX];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	cin >> G >> P;
	for (int i = 0; i < P; i++) {
		cin >> plane[i];
	}
	
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < P; i++) {
		int docking = Find(plane[i]);
		//도킹이 가능한 경우, 이 게이트에서는 이제 도킹이 불가능하고 그 전 번호의 게이트까지만 가능
		if (docking) {
			ans++;
			//그 전 게이트 또한 도킹이 완료된 경우 Union 과정에서 도킹이 가능한 부모를 찾아줌 
			Union(docking, docking - 1);
		}
		//docking이 0인 경우 현재 도킹이 가능한 게이트가 없다는 것을 의미 
		else break;
	}
	cout << ans;
	return 0;
}