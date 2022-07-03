import java.util.*;

class Solution {
    String[] Answer;
    String[] Orders;
    int[] Course; 
    int MaxCnt;
    Map<String, Integer> Comb;
    PriorityQueue<String> PQ;

    public void comb(String order, int idx, int c, String foods) {
        if (foods.length() == c) {
            // System.out.println(foods);
            
            char arr[] = foods.toCharArray();
            Arrays.sort(arr);
            foods = new String(arr);
            
            if (!Comb.containsKey(foods))
                Comb.put(foods, 0);
            
            Comb.put(foods, Comb.get(foods) + 1);
            MaxCnt = Math.max(MaxCnt, Comb.get(foods));
            return;
        }
        
        for (int i = idx; i < order.length(); ++i) {
            comb(order, i + 1, c, foods + order.charAt(i));
        }
    }
    
    public String[] solution(String[] orders, int[] course) {
        Orders = orders;
        Course = course;
        PQ = new PriorityQueue<>();
        
		for (int c : course) {
            Comb = new HashMap<>();
            MaxCnt = 0;
            
            for (String order : orders) {
                comb(order, 0, c, "");
            }
            
 			for (String k : Comb.keySet()) {
                if (Comb.get(k) == MaxCnt && MaxCnt > 1)
                    PQ.offer(k);
            }      
        }
        Answer = new String[PQ.size()];
        int idx = 0;
        while (!PQ.isEmpty()) {
			Answer[idx++] = PQ.poll();
        }
        
        return Answer;
    }
}
