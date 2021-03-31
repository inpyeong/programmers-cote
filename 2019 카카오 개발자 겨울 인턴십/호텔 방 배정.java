import java.util.*;

class Solution {
    Map<Long, Long> room = new HashMap<>();
    
    long find(long n) {
        if(room.containsKey(n) == false) return n;
        room.put(n, find(room.get(n)));
        return room.get(n);
    }
    
    public long[] solution(long k, long[] room_number) {
        int n = room_number.length;
        long[] answer = new long[n];
        for(int i = 0; i < n; ++i) {
            long num = room_number[i];
            if(room.containsKey(num) == false) {
                answer[i] = num;
                room.put(num, find(num+1));
            }
            else {
                long nextNum = find(num);
                answer[i] = nextNum;
                room.put(nextNum, find(nextNum+1));
            }
        }
        return answer;
    }
}
