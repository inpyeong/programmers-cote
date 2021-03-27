import java.util.*;

class Solution {
    static final int UP = 0;
    static final int RIGHT = 1;
    static final int DOWN = 2;
    static final int LEFT = 3;
    
    int[][] D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // ccw, idx, dir
    int[][][] Drot = {{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}},
                      {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}}};
    int[][][] Dcor = {{{-1, 1}, {1, 1}, {1, -1}, {-1, -1}},
                      {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}}};
    
    class Point {
        Point(int row, int col, int dir, int time) {
            this.row = row;
            this.col = col;
            this.dir = dir;
            this.time = time;
        }
        int row, col, dir, time;
    }
    
    int[][] Board;
    int N;
    Queue<Point[]> Q = new LinkedList<>();
    boolean[][][] Visited = new boolean[100][100][4];
    
    boolean isValid(Point[] pt) {
        for (int i = 0; i < 2; ++i) {
            if (pt[i].row < 0 || pt[i].row >= N || pt[i].col < 0 || pt[i].col >= N)
                return false;
            if (Board[pt[i].row][pt[i].col] == 1)
                return false;
            if (Visited[pt[i].row][pt[i].col][pt[i].dir] == true) {
                return false;
            }
        }
        return true;
    }
    
    int rotate(Point[] curr, int ccw, int idx) {
        Point[] newPt = new Point[2];
        int a = idx, b = (idx + 1) % 2;
        int dir = curr[a].dir;
        
        newPt[0] = new Point(curr[a].row, curr[a].col, (curr[a].dir + (ccw == 0 ? 1 : 3)) % 4, curr[a].time + 1);
        newPt[1] = new Point(curr[b].row + Drot[ccw][dir][0], curr[b].col + Drot[ccw][dir][1], (curr[b].dir + (ccw == 0 ? 1 : 3)) % 4, curr[b].time + 1);
        
        if (isValid(newPt) == false) return 0;
        if (Board[curr[a].row + Dcor[ccw][dir][0]][curr[a].col + Dcor[ccw][dir][1]] == 1) return 0;
        
        for (int i = 0; i < 2; ++i) {
            if (newPt[i].row == N-1 && newPt[i].col == N-1) return newPt[i].time;
            Visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
        }
        Q.add(new Point[]{newPt[0], newPt[1]});
        return 0;
    }
    
    public int solution(int[][] board) {
        Board = board;
        N = board.length;
        Q.add(new Point[]{new Point(0, 0, RIGHT, 0), new Point(0, 1, LEFT, 0)});   
        Visited[0][0][RIGHT] = true;
        Visited[0][1][LEFT] = true;
        Point[] curr = new Point[2];
        Point[] newPt = new Point[2];
        
        while ((curr = Q.poll()) != null) {
            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 2; ++i) {
                    newPt[i] = new Point(curr[i].row + D[j][0], curr[i].col + D[j][1], curr[i].dir, curr[i].time + 1);
                }
                
                if (isValid(newPt) == false) continue;
                
                for (int i = 0; i < 2; ++i) {
                    if (newPt[i].row == N-1 && newPt[i].col == N-1) return newPt[i].time;
                    Visited[newPt[i].row][newPt[i].col][newPt[i].dir] = true;
                }
                Q.add(new Point[]{newPt[0], newPt[1]});
            }     
            
            for (int ccw = 0; ccw < 2; ++ccw) {
                // 회전축 2개
                for (int i = 0; i < 2; ++i) {
                    int ret = rotate(curr, ccw, i);
                    if(ret != 0) return ret;
                }
            }
        } 
        
        int answer = 0;
        return answer;
    }
}
