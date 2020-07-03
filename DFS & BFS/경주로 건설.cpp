#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

const int INF = 0x3f3f3f;
int N, answer = INF;

struct Load {
    int x; int y; int direction; int corner; 
};

int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

int buildLoad(vector<vector<int>> board, int corner) {
    queue<Load> load;
    int visited[25][25][4];
    memset(visited, 0, sizeof(visited));
    load.push({ 0,0,1,0 });
    load.push({ 0,0,3,0 });
    while (!load.empty()) {
        Load l = load.front();
        load.pop();
        if (l.x == N-1 && l.y == N-1) {
            return visited[l.x][l.y][l.direction] + 1;
        }
        for (int i = 0; i < 4; i++) {
            int nx = l.x + dir[i][0];
            int ny = l.y + dir[i][1];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny]) continue;
            int now = visited[l.x][l.y][l.direction] + 1;
            if (now < visited[nx][ny][i]) continue;
            if (l.direction == i) load.push({ nx, ny, i, corner });
            else {
                if (l.corner < corner) load.push({ nx, ny, i, ++corner });
            }
        }
    }
    return INF;
}

int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i = 1; i <= N * N; i++) {
        int dist = buildLoad(board, i);
        dist = (dist - i) * 100 + i * 500;
        if (dist < answer) answer = dist;
    }
    return answer;
}

int main() {
    printf("%d ", solution({ {0, 0, 1, 0} ,{0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0 } }));
    printf("%d", solution({ {0, 0, 0},{0, 0, 0},{0, 0, 0} }));
    return 0;
}