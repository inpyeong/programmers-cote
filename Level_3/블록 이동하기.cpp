#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 1,  0, -1 };
int dy[] = { 1, 0, -1,  0 };
int ndx[] = { -1,  1,  1, -1 };
int ndy[] = {  1,  1, -1, -1 };

int n;
bool discovered[100][100][4];

struct Robot {
    int x, y, dir;
    int time;
    Robot(int a, int b, int d, int t) {
        x = a;
        y = b;
        dir = d;
        time = t;
    }
};

bool checkRange(int x, int y, int xx, int yy) {
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    if(xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
    return true;
}

int solution(vector<vector<int>> board) {
    
    n = board.size();
    int destX = n - 1;
    int destY = n - 1;
    
    queue<Robot> q;
    discovered[0][0][0] = true;
    q.push(Robot(0, 0, 0, 0));
    
    while(!q.empty()) {
    	int x = q.front().x;
    	int y = q.front().y;
        int dir = q.front().dir;
        int time = q.front().time;
        q.pop();
        
    	int xx = x + dx[dir];
    	int yy = y + dy[dir];
        
        if(x == destX && y == destY) return time;
        if(xx == destX && yy == destY) return time;
        
        int nx, ny, nxx, nyy;
        
        // 상하좌우
        for(int k = 0; k < 4; ++k) {
            nx = x + dx[k];
            ny = y + dy[k];
            nxx = xx + dx[k];
            nyy = yy + dy[k];
            
            if(!checkRange(nx, ny, nxx, nyy)) continue;
            if(discovered[nx][ny][dir]) continue;
            if(board[nx][ny] == 1 || board[nxx][nyy] == 1) continue;
            
            discovered[nx][ny][dir] = true;
            q.push(Robot(nx, ny, dir, time+1));
        }
        
        // x, y를 축으로 90도 회전
        for(int i = 1; i < 4; i+=2) {
            int ndir = (dir + i) % 4;
            nxx = x + dx[ndir];
            nyy = y + dy[ndir];
            
            int rx, ry;
            if(i == 1) {
                // 시계 방향
                rx = x + ndx[ndir];
                ry = y + ndy[ndir];
            }
            else {
                // 반시계 방향
                rx = x + ndx[dir];
                ry = y + ndy[dir];
            }
            
            if(!checkRange(rx, ry, nxx, nyy)) continue;
            if(discovered[x][y][ndir]) continue;
            if(board[nxx][nyy]) continue;
            if(board[rx][ry]) continue;
            
            discovered[x][y][ndir] = true;
            q.push(Robot(x, y, ndir, time+1));
        }
        
        // xx, yy를 축으로 90도 회전
        dir = (dir + 2) % 4;
        for(int i = 1; i < 4; i+=2) {
            int ndir = (dir + i) % 4;
            nx = xx + dx[ndir];
            ny = yy + dy[ndir];
            
            int rx, ry;
            if(i == 1) {
                // 시계 방향
                rx = xx + ndx[ndir];
                ry = yy + ndy[ndir];
            }
            else {
                // 반시계 방향
                rx = xx + ndx[dir];
                ry = yy + ndy[dir];
            }
            
            if(!checkRange(rx, ry, nx, ny)) continue;
            if(board[nx][ny]) continue;
            if(board[rx][ry]) continue;
            
            ndir = (ndir + 2) % 4;
            if(discovered[nx][ny][ndir]) continue;
            discovered[nx][ny][ndir] = true;
            q.push(Robot(nx, ny, ndir, time+1));
        }
    }
}
