#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M;
int days = -1;
bool flag = false;
int tomato[MAX][MAX];
int visited[MAX][MAX];
int dx[] = { 1,0,-1,0 }; // 방향
int dy[] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void tomato_bfs() {
    while (!q.empty()) { // 큐가 빌 때 까지
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {// 주변 노드 탐색
            int na = a + dx[i];
            int nb = b + dy[i];
            if (na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0) {
                q.push(make_pair(na, nb));// 익지 않은 토마토가 익은 토마토가 됨. 큐에 다시 저장.
                visited[na][nb] = visited[a][b] + 1;// 날짜 갱신
            }
        }
    }
}

int cal_days() {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if (days <= visited[i][j]) {
                days = visited[i][j];
            }
            if (tomato[i][j] == 0 && visited[i][j] == -1) {
                days = -1;
                flag = true;
                break; // 익지 않은 토마토가 존재하는데, 그 노드를 방문한 적이 없다면.
            }
        }
        if (flag)
            break;
    }
    return days;
}

int main() {
    cin >> M >> N;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> tomato[i][j];
            visited[i][j] = -1;

            if (tomato[i][j] == 1) {// 익은 토마토라면
                q.push(make_pair(i,j));// 큐에 넣어줌
                visited[i][j]++;// 방문 여부 체크
            }
        }
    }
    tomato_bfs();
    cout << cal_days();
}
