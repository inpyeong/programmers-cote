import java.util.*;

class Solution {
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
    
    int N, answer;
    Queue<Car> myQue = new LinkedList<>();
    boolean[][][] discovered = new boolean[N][N][4];
    int[][] D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public int solution(int[][] board) {
        N = board.length;
        
        myQue.add(new Car(0, 0, 1, 0));
        myQue.add(new Car(0, 0, 3, 0));
        discovered[0][0][0] = true;
        discovered[0][0][2] = true;
        
        while(!myQue.isEmpty()) {
            Car car = myQue.poll();
            if(car.y == N-1 && car.x == N-1) {
                answer = car.cost;
                break;
            }
			for(int i = 0; i < 4; ++i) {
                int ny = car.y + D[i][0];
                int nx = car.x + D[i][1];
                if(ny < 0 || ny >= N || nx < 0 || nx >= N)
                    continue;
                if(board[ny][nx] != 1 && !discovered[ny][nx][i]) {
                    discovered[ny][nx][i] = true;
                    if((i / 2) != (car.d / 2)) 
                        myQue.add(new Car(ny, nx, i, car.cost + 600));
                    else
                        myQue.add(new Car(ny, nx, i, car.cost + 100));
                }
            }            
        }
        
        return answer;
    }
}
