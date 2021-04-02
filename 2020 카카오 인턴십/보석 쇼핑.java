import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        Map<String, Integer> gemList = new HashMap<>();
        for(String gem : gems)
            gemList.put(gem, 1);
        int gemSize = gemList.size();
        int start = 0, dist = 100000;
        
        gemList.clear();
        Queue<String> q = new LinkedList<>();
        int _start = 0;
        for(String gem : gems) {
        	if(gemList.containsKey(gem)) {
                gemList.put(gem, gemList.get(gem) + 1);
            }
            else gemList.put(gem, 1);
            q.add(gem);
            while(true) {
                if(gemList.get(q.peek()) > 1) {
                    gemList.put(q.peek(), gemList.get(q.peek()) - 1);
                    q.remove();
                    _start++;
                }
                else break;
            }
            if(gemList.size() == gemSize && dist > q.size()) {
                start = _start;
                dist = q.size();
            }
        }
        
        int[] answer = { start+1, start + dist };
        return answer;
    }
}
