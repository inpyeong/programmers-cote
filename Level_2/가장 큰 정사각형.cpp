#include <vector>
#include <iostream>

using namespace std;

int cache[1000][1000];

int solution(vector<vector<int>> board)
{
    int answer = board[0][0], w = board[0].size(), h = board.size();
    for(int i = 1; i < h; ++i)
        for(int j = 1; j < w; ++j)
            if(board[i][j]) {
                board[i][j] = min(board[i-1][j], board[i][j-1]);
                board[i][j] = min(board[i][j], board[i-1][j-1]) + 1;
                answer = max(answer, board[i][j]);
            }
    return answer * answer;
}
