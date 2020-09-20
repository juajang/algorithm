#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x7FFFFFFF;
int N, M;
vector< pair<int, int> > graph[501];
long long res[501];

int main() {
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
    }
    for (int i = 1; i <= N; i++) {
        res[i] = INF;
    }
    res[1] = 0; //처음 시작할 정점 

    bool check = false;
    //각 노드마다 모든 엣지에 대해 Relax
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < graph[j].size(); k++) {
                int nextV = graph[j][k].first;
                int nextCost = graph[j][k].second;
                if ((res[j] != INF) && (res[nextV] > res[j] + nextCost)) {
                    res[nextV] = res[j] + nextCost;
                    if (i == N) { //N-1까지 돌고 N번째에서 값이 갱신되면 음수 싸이클
                        check = true;
                        break;
                    }
                }
            }
        }
    }

    if (check) cout << "-1\n";
    else {
        for (int i = 2; i <= N; i++) {
            if (res[i] == INF) cout << "-1\n";
            else cout << res[i] << "\n";
        }
    }
    return 0;
}