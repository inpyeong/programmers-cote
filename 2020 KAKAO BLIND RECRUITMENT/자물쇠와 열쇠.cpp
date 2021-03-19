#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<vector<int> >& v) {
    cout << "=================" << endl;
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << "=================" << endl;
}

vector<vector<int> > rotateKey(const vector<vector<int> > key) {
    int m = key.size();
    vector<vector<int> > keyCopy(m, vector<int>(m, 0));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j) 
            keyCopy[j][m - i - 1] = key[i][j];
    return keyCopy;
}

bool canOpen(const vector<vector<int> >& board, const vector<vector<int> >& key, int m, int n) {
    vector<vector<int> > boardCopy;
    for(int i = 0; i < m+n-1; ++i) {
        for(int j = 0; j < m+n-1; ++j) {
            bool ok1 = true;
            boardCopy = board;
            for(int k = i; k < i+m && ok1; ++k) {
                for(int l = j; l < j+m; ++l) {
                    if(k >= m-1 && k < n+m-1 && l >= m-1 && l < n+m-1) {
                        if(boardCopy[k][l] && key[k-i][l-j]) {
                            ok1 = false;
                            break;
                        }
                        if(!boardCopy[k][l] && key[k-i][l-j])
                            boardCopy[k][l] = 1;
                    }
                }
            }
            if(!ok1) continue;
            bool ok2 = true;
            for(int k = m-1; k < n+m-1 && ok2; ++k)
                for(int l = m-1; l < n+m-1; ++l) {
                    if(!boardCopy[k][l]) {
                        ok2 = false;
                        break;
                    }
                }
            if(ok2) return true;
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int m = key.size(), n = lock.size();
    int boardSz = (n + 2 * m - 2);
    vector<vector<int> > board(boardSz, vector<int>(boardSz, 0));
    for(int i = m-1; i < n+m-1; ++i)
        for(int j = m-1; j < n+m-1; ++j)
            board[i][j] = lock[i-m+1][j-m+1];
    for(int i = 0; i < 4; ++i) {
        key = rotateKey(key);
        if(canOpen(board, key, m, n))
            return true;
    }
    return false;
}
