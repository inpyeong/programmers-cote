#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int answer;
stack<int> basket;

void putDollInBasket(int doll) {
    // 만약 바구니가 비어있다면 인형을 넣고 끝낸다.
    if(basket.empty()) 
        basket.push(doll);
    // 만약 바구니 제일 위에 있는 인형과 같다면
    else if(basket.top() == doll) {
        // 인형 두 개가 터진다.
        answer += 2;
        basket.pop();
    }
    else
        basket.push(doll);
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    for(int move : moves) {
        move--;    
        for(int i = 0; i < n; ++i) 
            // 만약 인형을 발견했다면
            if(board[i][move] != 0) {
                // 바구니에 인형을 넣는다.
                putDollInBasket(board[i][move]);
                // 기계에서 인형을 제거한다.
                board[i][move] = 0;
                break;
            }    
    }
    return answer;
}
