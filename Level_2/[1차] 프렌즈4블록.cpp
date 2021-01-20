#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// 오른, 오른 아래 대각, 아래
int dx[] = { 1, 1, 0 };
int dy[] = { 0, 1, 1 };

void printBoard(const vector<string>& board) {
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[0].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    for(int i = 0; i < board[0].size(); ++i)
        cout << '-' << " ";
    cout << endl;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    set<pair<int, int> > coords;
    while(true) {
        for(int y = 0; y < m-1; ++y) {
            for(int x = 0; x < n-1; ++x) {
                if(board[y][x] == '0') continue;
                int cnt = 0;
                for(int k = 0; k < 3; ++k) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(board[ny][nx] == board[y][x]) cnt++;
                }
                // 4칸이 같으면 coords에 삽입
                if(cnt == 3) {
                    for(int k = 0; k < 3; ++k) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        coords.insert({ ny, nx });
                    }
                    coords.insert({ y, x });
                }
            }
        }
        answer += coords.size();
        // 사라질 블록이 없으면 종료
        if(coords.size() == 0) break;
        // 지워야 하는 블록 지우기
        for(auto iter = coords.begin(); iter != coords.end(); ++iter) {
            int y = iter->first;
            int x = iter->second;
            board[y][x] = '0';
        }
        coords.clear();
        // 빈 공간에 블록 채워넣기
        // 먼저 열을 고정
        for(int x = 0; x < n; ++x) {
            // empty: 열에서 빈 칸의 개수
            // lastEmptyCoord: 아래서부터 마지막으로 빈칸을 발견한 y좌표
            // flag: 아래서부터 빈칸을 확인해갈 때 빈칸 발견하면 true
            while(true) {
                int empty = 0, lastEmptyCoord = -1;
                bool flag = false;
                for(int y = m-1; y >= 0; --y) {
                    // 빈칸을 처음 만나면 flag는 true
                    if(!flag && board[y][x] == '0') flag = true;
                    if(flag && board[y][x] == '0') empty++;
                    if(flag && board[y][x] != '0') {
                        lastEmptyCoord = y + 1;
                        break;
                    }
                }
                // 옮길 블록이 없으면 다음 열 검사
                if(lastEmptyCoord == -1) break;
                // 빈 칸의 개수만큼 블록을 아래로 이동시킨다.
                for(int y = lastEmptyCoord-1; y >= 0; --y) {
                    board[y+empty][x] = board[y][x];
                    board[y][x] = '0';
                }
            }
        } 
    }
    return answer;
}
