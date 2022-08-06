import java.util.*;

class Solution {
    public static final int DIR = 4;
    
    public int M, N, K;
    public int[][] Key, Lock, KeLock;
    public boolean Answer;
    
    public void initGlobalVars(int[][] key, int[][] lock) {
        M = key.length;
        N = lock.length;
        K = N + 2 * (M - 1);
        Key = key;
        Lock = lock;
    }
    
    public void rotateKey() {  // (y, x) => (x, (M - 1) - y)
        int[][] temp = new int[M][M];
        for (int y = 0; y < M; ++y) 
            for (int x = 0; x < M; ++x) 
                temp[x][(M - 1) - y] = Key[y][x];
        Key = temp;
    }
    
    public void initKeLock(int[] keyPos) {  // Initialize KeLock
        KeLock = new int[K][K];
        // Lock
        for (int i = M - 1; i < (M - 1) + N; ++i) {
            for (int j = M - 1; j < (M - 1) + N; ++j) 
                KeLock[i][j] = Lock[i - (M - 1)][j - (M - 1)];
        }
        
        // Key
        for (int i = keyPos[0]; i < keyPos[0] + M; ++i) {
            for (int j = keyPos[1]; j < keyPos[1] + M; ++j) 
                KeLock[i][j] += Key[i - keyPos[0]][j - keyPos[1]];
        }
    }
    
    public boolean isKeyMatched() {  // Check if Key is Matched
        // Lock
        boolean ret = true;
        for (int i = M - 1; i < (M - 1) + N; ++i) {
            for (int j = M - 1; j < (M - 1) + N; ++j) {
                int KeLockVal = KeLock[i][j];
                if (KeLockVal != 1) ret = false;
            }
        }
        return ret;
    }
    
    public boolean go() {
        for (int i = 0; i < DIR; ++i) {
            rotateKey();
            for (int j = 0; j < (M - 1) + N; ++j) {
                for (int k = 0; k < (M - 1) + N; ++k) {
                    initKeLock(new int[]{j, k});
                    if (isKeyMatched()) return true;
                }
            }
		}
        return false;
    }
    
    public boolean solution(int[][] key, int[][] lock) {
        initGlobalVars(key, lock);
        return go();
    }
}
