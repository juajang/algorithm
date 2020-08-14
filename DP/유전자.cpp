#include <iostream>
#include <algorithm>
#define MAX 510
using namespace std;

string str;
char DNA[MAX];
int cache[MAX][MAX];

int main() {
	cin >> str;
	int N = str.length();
	for (int i = 1; i <= N; i++) {
		DNA[i] = str[i - 1];
	}
	
	//단어의 길이 2부터 전체 길이까지 
	for (int size = 1; size < N; size++) {

		//전체 문자열 중 해당 길이의 모든 문자열 확인 
		for (int start = 1; size + start <= N; start++) {
			int end = size + start;

			//어떤 X가 KOI 유전자라면, aXt와 gXc도 KOI 유전자이다.
			if ((DNA[start] == 'a' && DNA[end] == 't') || (DNA[start] == 'g' && DNA[end] == 'c')) {
				cache[start][end] = cache[start + 1][end - 1] + 2;
			}

			//어떤 X와 Y가 KOI 유전자라면, 이 둘을 연결한 XY도 KOI 유전자이다.
			for (int mid = start; mid < end; mid++) {
				cache[start][end] = max(cache[start][end], cache[start][mid] + cache[mid + 1][end]);
			}
		}
	}

	cout << cache[1][N] << endl;
	return 0;
}