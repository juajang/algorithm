#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f;

struct Load {
    int x; int y; int direction; int corner; 
};

int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

int solution(vector<vector<int>> board) {
    int col = board.size();
    int row = board[0].size();
    
    queue<Load> load;
    int visited[25][25][4];

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                visited[i][j][k] = INF;
            }
        }
    }

    visited[0][0][0] = 0;
    visited[0][0][1] = 0;
    visited[0][0][2] = 0;
    visited[0][0][3] = 0;

    load.push({ 0,0,0,0 });
    load.push({ 0,0,1,0 });
    load.push({ 0,0,2,0 });
    load.push({ 0,0,3,0 });

    while (!load.empty()) {
        Load l = load.front();
        load.pop();

        for (int i = 0; i < 4; i++) {
            int nx = l.x + dir[i][0];
            int ny = l.y + dir[i][1];
            if (abs(l.direction - i) == 2) continue;
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || board[nx][ny]) continue;
            int next = 0;
            if (l.direction == i) {
                next = visited[l.x][l.y][l.direction] + 100;
                load.push({ nx, ny, i, l.corner });
            }
            else {
                next = visited[l.x][l.y][l.direction] + 600;
                ++l.corner;
            }
            if (next >= visited[nx][ny][i]) continue;
            visited[nx][ny][i] = next;
            load.push({ nx, ny, i, ++l.corner });
        }
    }
    int answer = INF;
    for (int i = 0; i < 4; i++) {
        if (visited[row - 1][col - 1][i] < answer) answer = visited[row - 1][col - 1][i];
    }
    return answer;
}

int main() {
    printf("%d ", solution({ {0, 0, 1, 0} ,{0, 0, 0, 0},{0, 1, 0, 1},{1, 0, 0, 0 } }));
    printf("%d", solution({ {0, 0, 0},{0, 0, 0},{0, 0, 0} }));
    return 0;
}