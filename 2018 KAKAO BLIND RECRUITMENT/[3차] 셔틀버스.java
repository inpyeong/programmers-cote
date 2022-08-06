import java.util.*;

class Solution {
    int N, T, M;
    int[] Timetable;
    Queue<Integer> Q;
    
    public int[] ttToMinutes(String[] tt) {
        int[] ret = new int[tt.length];
            
        for (int i = 0; i < tt.length; ++i) {
            String[] tmp = tt[i].split(":");
            ret[i] = Integer.parseInt(tmp[0]) * 60 + Integer.parseInt(tmp[1]);
        }
        
        return ret;
    }
    
    public void initGlobalVars(int n, int t, int m, String[] timetable) {
        N = n;
        T = t;
        M = m;
        Timetable = ttToMinutes(timetable);
        Arrays.sort(Timetable);
        System.out.println(Arrays.toString(Timetable));
        Q = new LinkedList<>();
    }
    
    public String go() {
        String ret = "";
        
        int crewIdx = 0;
        int busArrivedTime = 9 * 60;
        int lastCrewArrivedTime = -1;
        int numOfBusCrew = 0;
        for (int i = 0; i < N; ++i) {
            
            for ( ; crewIdx < Timetable.length; ++crewIdx) {
                int crewArrivedTime = Timetable[crewIdx];
                if (crewArrivedTime <= busArrivedTime) {
                    Q.add(crewArrivedTime);
                    System.out.println(crewArrivedTime);
                }
                else break;
            }
            
            for (numOfBusCrew = 0; numOfBusCrew < M; ++numOfBusCrew) {
                if (Q.isEmpty()) break;
                lastCrewArrivedTime = Q.poll();
            }
            
            busArrivedTime += (i == (N - 1)) ? 0 : T;
        }
        
        int tmpRet = 0;
        
        if (lastCrewArrivedTime == -1) {
            tmpRet = busArrivedTime;
        } else {
            if (numOfBusCrew < M) {
                tmpRet = busArrivedTime;
            } else {
                tmpRet = lastCrewArrivedTime - 1;
            }
        }
        
        ret = String.format("%02d:%02d", tmpRet / 60, tmpRet % 60);
        
        // System.out.println("busArrivedTime: " + busArrivedTime);
        // System.out.println("lastCrewArrivedTime: " + lastCrewArrivedTime);
        // System.out.println("numOfBusCrew: " + numOfBusCrew);
        // System.out.println("Is Q Empty? " + Q.isEmpty());
        // System.out.println("tmpRet: " + tmpRet);
        
        return ret;
    }
    
    public String solution(int n, int t, int m, String[] timetable) {
        initGlobalVars(n, t, m, timetable);
        return go();
    }
}
