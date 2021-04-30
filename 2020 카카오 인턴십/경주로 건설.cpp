#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 25, INF = 987654321;

struct Car {
    int y, x;
    int dir;
    int cost;
    Car(int _y, int _x, int _dir, int _cost): y(_y), x(_x), dir(_dir), cost(_cost) {}    
};

int n, answer = INF;
queue<Car> q;
int discovered[MAX_N][MAX_N][4];

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool checkVertical(int d, int nd) {
    if(d == 0 && nd == 2) return true;
    if(d == 0 && nd == 3) return true;
    if(d == 1 && nd == 2) return true;
    if(d == 1 && nd == 3) return true;
    if(d == 2 && nd == 0) return true;
    if(d == 2 && nd == 1) return true;
    if(d == 3 && nd == 0) return true;
    if(d == 3 && nd == 1) return true;
    return false;
}

void bfs(const vector<vector<int> >& board) {
    memset(discovered, -1, sizeof(discovered));
    q.push(Car(0, 0, 1, 0));
    q.push(Car(0, 0, 3, 0));
    while(!q.empty()) {
        Car now = q.front();
        q.pop();
        if(now.y == (n-1) && now.x == (n-1)) {
            answer = min(answer, now.cost);
            continue;
        }
        for(int i = 0; i < 4; ++i) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            int newAddCost = 100;
            if(checkVertical(now.dir, i))
                newAddCost += 500;
            // board 안에 위치하고
            if(ny >= 0 && nx >= 0 && ny < n && nx < n) {
                // 벽이 아니고
                if(board[ny][nx] != 1) {
                    // 만약 방문하지 않았거나, 이전에 방문했었을 때의 경주로 비용보다 싸다면
                    if(discovered[ny][nx][i] == -1 || (discovered[ny][nx][i] > now.cost + newAddCost)) {
                        discovered[ny][nx][i] = now.cost + newAddCost;
                        q.push(Car(ny, nx, i, discovered[ny][nx][i]));
                    }
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    bfs(board);
    return answer;
}
