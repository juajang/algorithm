#include <iostream>
#include <vector>
using namespace std;

int direction[9][2] = { { 0, 0 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 } };

struct Fish {
	int x; int y; int dir;
};

int max(int a, int b) { return a > b ? a : b; }

int dfs(int sum, Fish shark, vector<vector<int>> MAP, vector<Fish> fish) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << MAP[i][j] << " " << fish[MAP[i][j]].dir << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	shark.dir = fish[MAP[shark.x][shark.y]].dir;
	sum += MAP[shark.x][shark.y];
	MAP[shark.x][shark.y] = 0;
	fish[MAP[shark.x][shark.y]] = { 0, 0, 0 };

	for (int i = 1; i <= 16; i++) {
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;
		if (MAP[x][y] == 0) continue;  

		for (int j = 0; j < 8; j++) {
			int ndir = dir + j <= 8 ? dir + j : dir + j - 8;
			int nx = x + direction[ndir][0];
			int ny = y + direction[ndir][1];
			if (shark.x == nx && shark.y == ny) continue;
			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		 
			int next = MAP[nx][ny];
			MAP[nx][ny] = MAP[x][y];
			MAP[x][y] = next;
			fish[i].x = nx; fish[i].y = ny; fish[i].dir = ndir; 
			fish[next].x = x; fish[next].y = y; 
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << MAP[i][j] << " " << fish[MAP[i][j]].dir << "| ";
		}
		cout << "\n";
	}
	cout << "\n";


	int max_sum = sum;
	for (int i = 1; i <= 3; i++) {
		int sdir = shark.dir;
		int nx = shark.x + direction[sdir][0] * i;
		int ny = shark.y + direction[sdir][1] * i;
		printf("%d %d %d: %d %d + %d %d -> %d %d\n", i, sdir, sum, shark.x, shark.y, direction[sdir][0] * i, direction[sdir][1] * i, nx, ny);
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (MAP[nx][ny] == 0) continue;
		max_sum = max(dfs(sum, { nx, ny, sdir }, MAP, fish), max_sum);
	}
	
	return max_sum;
}

int main() {
	int no, dir;
	vector<vector<int>> MAP(4, vector<int>(4,0));
	vector<Fish> fish(17);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> no >> dir;
			fish[no] = { i,j,dir };
			MAP[i][j] = no;
		}
	}

	Fish shark = { 0, 0, 0 };
	int answer = dfs(0, shark, MAP, fish);

	cout << answer;
	return 0;
}
