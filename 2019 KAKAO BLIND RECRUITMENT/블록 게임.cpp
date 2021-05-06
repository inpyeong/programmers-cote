#include <string>
#include <vector>

using namespace std;

int n;
int dy[5][6], dx[5][6];

void init() {
    dy[0][0] = 0; dy[0][1] = 1; dy[0][2] = 1; dy[0][3] = 1; dy[0][4] = 0; dy[0][5] = 0;
    dx[0][0] = 0; dx[0][1] = 0; dx[0][2] = 1; dx[0][3] = 2; dx[0][4] = 1; dx[0][5] = 2;
    
    dy[1][0] = 0; dy[1][1] = 1; dy[1][2] = 2; dy[1][3] = 2; dy[1][4] = 0; dy[1][5] = 1;
    dx[1][0] = 0; dx[1][1] = 0; dx[1][2] = 0; dx[1][3] = -1; dx[1][4] = -1; dx[1][5] = -1;
    
    dy[2][0] = 0; dy[2][1] = 1; dy[2][2] = 2; dy[2][3] = 2; dy[2][4] = 0; dy[2][5] = 1;
    dx[2][0] = 0; dx[2][1] = 0; dx[2][2] = 0; dx[2][3] = 1; dx[2][4] = 1; dx[2][5] = 1;
    
    dy[3][0] = 0; dy[3][1] = 1; dy[3][2] = 1; dy[3][3] = 1; dy[3][4] = 0; dy[3][5] = 0;
    dx[3][0] = 0; dx[3][1] = 0; dx[3][2] = -1; dx[3][3] = -2; dx[3][4] = -1; dx[3][5] = -2;
    
    dy[4][0] = 0; dy[4][1] = dy[4][2] = dy[4][3] = 1; dy[4][4] = 0; dy[4][5] = 0;
    dx[4][0] = 0; dx[4][1] = -1; dx[4][2] = 0; dx[4][3] = 1; dx[4][4] = -1; dx[4][5] = 1;
}

int check(int y, int x, vector<vector<int> >& board) {
    int val = board[y][x];
    for(int i = 0; i < 5; ++i) {
        bool flag = true;
        for(int j = 0; j < 4; ++j) {
            int ny = y + dy[i][j];
            int nx = x + dx[i][j];
            if((ny < 0 || ny >= n || nx < 0 || nx >= n) || board[ny][nx] != val) {
                flag = false;
                break;
            }
        }
        if(flag == true) {
            bool flag2 = true;
            for(int j = 4; j < 6; ++j) {
                int ny = y + dy[i][j];
                int nx = x + dx[i][j];
                if((ny < 0 || ny >= n || nx < 0 || nx >= n) || board[ny][nx] != 0) {
                    flag2 = false;
                    break;
                }
                for(int k = ny; k >= 0; --k) {
                    if(board[k][nx] != 0) {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2 == false)
                    break;
            }
            if(flag2 == true)
                return i;
        }
    }
    return -1;
}

void remove(int y, int x, int idx, vector<vector<int> >& board) {
    for(int i = 0; i < 4; ++i) {
        int ny = y + dy[idx][i];
        int nx = x + dx[idx][i];
        board[ny][nx] = 0;
    }
}

int solution(vector<vector<int>> board) {
    init();
    n = board.size();
    int answer = 0;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) {
            if(board[i][j] == 0)
                continue;
            int res = check(i, j, board);
            if(res != -1) {
                remove(i, j, res, board);
                answer++;
                j = -1;
            }
        }
    return answer;
}
