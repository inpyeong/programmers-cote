#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int move : moves) {
        int pos = move - 1;
        for(int r = 0; r < board.size(); ++r) {
            if(board[r][pos] != 0) {
                if(s.empty())
                    s.push(board[r][pos]);
                else {
                    if(board[r][pos] == s.top()) {
                        s.pop();
                        answer += 2;
                    }
                    else s.push(board[r][pos]);
                }
                board[r][pos] = 0;
                break;
            }
        }
    }
    return answer;
}
