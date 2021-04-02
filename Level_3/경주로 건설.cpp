#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int dx[] = { 0, 1,  0, -1 };
int dy[] = { 1, 0, -1,  0 };

struct Car {
    int y, x, cost, dir;
    Car(int a, int b, int c, int d): y(a), x(b), cost(c), dir(d) {}
};

int solution(vector<vector<int>> board) {
    int answer = INF, N = board.size();
    queue<Car> q;
    Car c = Car(0, 0, 0, -1);
    q.push(c);
    while(!q.empty()) {
        Car a = q.front();
        q.pop();
        if(a.y == N-1 && a.x == N-1) {
            answer = min(answer, a.cost);
            continue;
        }
        for(int i = 0; i < 4; ++i) {
            int ny = a.y + dy[i];
            int nx = a.x + dx[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int nc = a.cost;
            if(a.dir == -1 || a.dir == i) nc += 100;
            else if(a.dir != i) nc += 600;
            if(board[ny][nx] == 0 || board[ny][nx] >= nc) {
                board[ny][nx] = nc;
                Car p(ny, nx, nc, i);
                q.push(p);
            }
        }
    }
    return answer;
}
