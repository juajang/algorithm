#include <iostream>
#include <vector>
#define MAX 110

using namespace std;

int A, B, N, M, map[MAX][MAX];
int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };
int ans = true;

struct Robot {
	int y;
	int x;
	int d;
};
vector<Robot> robot(MAX);

int main() {
	cin >> A >> B >> N >> M;
	char d;
	for (int i = 1; i <= N; i++) {
		cin >> robot[i].x >> robot[i].y >> d;
		if (d == 'N') {
			robot[i].d = 1;
		}
		else if (d == 'E') {
			robot[i].d = 2;
		}
		else if (d == 'S') {
			robot[i].d = 3;
		}
		else if (d == 'W') {
			robot[i].d = 4;
		}
		map[robot[i].y][robot[i].x] = i;
 	}

	int curRobot, cnt;
	char cmd;
	for (int i = 0; i < M; i++) {
		cin >> curRobot >> cmd >> cnt;
		int ny = robot[curRobot].y;
		int nx = robot[curRobot].x;
		int nd = robot[curRobot].d;
	
		for (int j = 0; j < cnt; j++) {
			if (cmd == 'L') {
				nd = nd - 1 >= 1 ? nd - 1 : 4;
			}
			else if (cmd == 'R') {
				nd = nd + 1 <= 4 ? nd + 1 : 1;
			}
			else {
				ny += dir[nd][0];
				nx += dir[nd][1];
			}
			if (ny > B || ny < 1 || nx > A || nx < 1) {
				printf("Robot %d crashes into the wall", curRobot);
				return 0;
			}
			else {
				for (int k = 1; k <= N; k++) {
					if (curRobot == k) continue;
					if (ny == robot[k].y && nx == robot[k].x) {
						printf("Robot %d crashes into robot %d\n", curRobot, k);
						return 0;
					}
				}
			}
			//printf("move - %d %d %d\n", ny, nx, nd);
		}
		robot[curRobot].x = nx;
		robot[curRobot].y = ny;
		robot[curRobot].d = nd;
	}
	printf("OK\n");
	return 0;
}