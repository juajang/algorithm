#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> p;
int N, start, fin;

vector<p> lesson;
priority_queue<int, vector<int>, greater<int>> room;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> fin;
		lesson.push_back({ start,fin });
	}
	
	sort(lesson.begin(), lesson.end());
	//가장 빨리 끝나는 수업을 강의실에 추가  
	room.push(lesson[0].second);

	for(int i = 1; i < N; i++){
		start = lesson[i].first;
		fin = lesson[i].second;
		//현재 가장 빨리 끝나는 수업의 강의실에서 수업 가능한 경우 
		cout << room.top() << "\n";
		if (room.top() <= start) {
			printf("%d %d 이어서\n", start, fin);
			room.pop();
			room.push(fin);
		}
		//아니라면 강의실 추가 
		else {
			printf("%d %d 추가\n", start, fin);
			room.push(fin);
		}
	}
	cout << room.size();
	return 0;
}