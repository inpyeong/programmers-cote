import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int n = board.length, answer = 0;
        Stack<Integer> mystack = new Stack<>();
        for (int move : moves) {
            int pos = move - 1;
            for (int r = 0; r < n; ++r) {
                if (board[r][pos] != 0) {
                    if (mystack.empty()) {
                        mystack.push(board[r][pos]);
                    }
                    else {
                        int top = mystack.peek();
                        if (board[r][pos] == top) {
                            mystack.pop();
                            answer += 2;
                        }
                        else mystack.push(board[r][pos]);
                    }
                    board[r][pos] = 0;
                    break;
                }
            }
        }
        return answer;
    }
}
