#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> s;
    int answer = 0;
    
    for(int i = 0; i < moves.size(); ++i) {
        int level = 0, doll = -1;
        bool check = false;
        while(board[level][moves[i]-1] == 0) {
            if(level == board.size()-1) {
                check = true;
                break;
            }
            ++level;
        }
        // 해당 위치에 인형이 없는 경우
        if(check) continue;
        
        doll = board[level][moves[i]-1];
        board[level][moves[i]-1] = 0;
        if(!s.empty() && s.top() == doll) {
            answer += 2;
            s.pop();
        }
        else s.push(doll);
    }
    return answer;
}
