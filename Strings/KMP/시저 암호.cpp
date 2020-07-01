#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
string A, W, S;
map<char, int> m;

vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) pi[i] = ++j;
	}
	return pi;
}

bool KMP(string p, string S) {
	vector<int> pi = getPi(p);
	int m = (int)p.size(), n = (int)S.size();
	int j = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt > 1) return false;
		while (j > 0 && S[i] != p[j]) {
			j = pi[j - 1];
		}
		if (S[i] == p[j]) {
			if (j == m - 1) {
				cnt++;
				j = pi[j];
			}
			else j++;
		}
	}
	return cnt == 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		cin >> A >> W >> S; 
		int lenA = (int)A.length();
		int lenW = (int)W.length();
		map<int, char> shift; 
		vector<int> cnt; 
		for (int i = 0; i < lenA; i++) {
			shift[A[i]] = i; //알파벳에 해당하는 인덱스를 저장
		}

		int index;
		//가능한 시프트 값의 범위: 알파벳의 길이만큼
		for (int i = 0; i < lenA; i++) {
			if (KMP(W, S)) cnt.push_back(i);
			//각 단어의 알파벳의 인덱스를 1씩 시프트 
			for (int j = 0; j < lenW; j++) {
				//맨 끝에 있는 알파벳은 인덱스를 맨 처음으로 
				if (shift[W[j]] == lenA - 1) index = 0;
				else index = shift[W[j]] + 1;
				W[j] = A[index]; 
			}
		}

		if (cnt.size() == 0) cout << "no solution\n";
		else if (cnt.size() == 1) {
			cout << "unique: " << cnt[0] << "\n";
		}
		else {
			cout << "ambiguous: ";
			for (int i = 0; i < cnt.size(); i++) {
				cout << cnt[i] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}