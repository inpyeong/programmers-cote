import java.util.*;

class Solution {
    static final int MAX_N = 25;
    
    class Car {
        Car(int y, int x, int d, int cost) {
            this.y = y;
            this.x = x;
            this.d = d;
            this.cost = cost;
        }
        int y, x;
        int d;
        int cost;
    }
    
    int N, answer = Integer.MAX_VALUE;
    Queue<Car> myQue = new LinkedList<>();
    int[][] D = {{-1,0},{1,0},{0,-1},{0,1}};
    
    public int solution(int[][] board) {
        N = board.length;
        int[][][] discovered = new int[N][N][4];
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < 4; ++k)
                    discovered[i][j][k] = -1;
        
        myQue.add(new Car(0, 0, 1, 0));
        myQue.add(new Car(0, 0, 3, 0));
        discovered[0][0][1] = 0;
        discovered[0][0][3] = 0;
        while(!myQue.isEmpty()) {
            Car now = myQue.poll();
            if(now.y == (N-1) && now.x == (N-1)) {
                answer = Math.min(answer, now.cost);
                continue;
            }
            for(int i = 0; i < 4; ++i) {
                int ny = now.y + D[i][0];
                int nx = now.x + D[i][1];
                
                int newAddCost = 100;
                if((now.d/2) != (i/2))
                    newAddCost += 500;
                
                if(ny >= 0 && nx >= 0 && ny < N && nx < N) {
                    if(board[ny][nx] != 1) {
                        if(discovered[ny][nx][i] == -1 || (discovered[ny][nx][i] > now.cost + newAddCost)) {
                            discovered[ny][nx][i] = now.cost + newAddCost;
                            myQue.add(new Car(ny, nx, i, discovered[ny][nx][i]));
                        }
                    }
                }
            }
        }
        return answer;
    }
}
