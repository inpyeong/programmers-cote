#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

set<pair<int, int> >::iterator it;
int dy[] = { 0, 1, 1 };
int dx[] = { 1, 0, 1 };

bool checkBomb(const vector<string>& board, int m, int n, int y, int x) {
    for(int i = 0; i < 3; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n)
            return false;
       	if(board[y][x] != board[ny][nx])
            return false;
    }
    return true;
}

void bomb(vector<string>& board, const set<pair<int, int> >& bombList) {
    for(it = bombList.begin(); it != bombList.end(); ++it) {
        int y = it->first;
        int x = it->second;
        board[y][x] = '0';
    }
}

void move(vector<string>& board, int m, int n) {
    for(int j = 0; j < n; ++j) {
        for(int i = m-1; i >= 0; --i) {
            if(board[i][j] == '0') continue;
            int pos = i + 1;
            while(pos < m && board[pos][j] == '0') pos++;
            pos--;
            // 블록 밑에 빈 공간이 없다면 통과
            if(pos == i) continue;
            board[pos][j] = board[i][j];
            board[i][j] = '0';
        }
    }
}

void printBoard(const vector<string>& board, int m, int n) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            cout << board[i][j];
        cout << endl;
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true) {
        // 제거해야 할 블록좌표 리스트
        set<pair<int, int> > bombList;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // 빈 공간은 통과
                if(board[i][j] == '0') continue;
                // 2 x 2 조건을 만족하는지 확인
				if(checkBomb(board, m, n, i, j)) {
                    bombList.insert(make_pair(i, j));
                    for(int d = 0; d < 3; ++d)
                        bombList.insert(make_pair(i + dy[d], j + dx[d]));
                }
            }
        }
        if(bombList.size() == 0) break;
        answer += bombList.size();
        bomb(board, bombList);
        move(board, m, n); 
    }
    printBoard(board, m, n);
    return answer;
}
