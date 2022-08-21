import java.util.*;

class Solution {
    int answer;
    Map<Integer, List<Integer>> nodes;
    
    public void DFS(int currIdx, int sheepCnt, int wolfCnt, List<Integer> candi, int[] info) {
        if (info[currIdx] == 0) sheepCnt++;
        else wolfCnt++;
        
        if (sheepCnt <= wolfCnt) return;
        
        answer = Math.max(sheepCnt, answer);
        List<Integer> nextCandi = new ArrayList<>();
        nextCandi.addAll(candi);
        if (nodes.containsKey(currIdx))
            nextCandi.addAll(nodes.get(currIdx));
        nextCandi.remove(Integer.valueOf(currIdx));
        
        for (int nC : nextCandi)
            DFS(nC, sheepCnt, wolfCnt, nextCandi, info);
    }
    
    public int solution(int[] info, int[][] edges) {
        answer = 0;
        nodes = new HashMap<>();
        
     	for (int[] e : edges) {
            if (!nodes.containsKey(e[0]))
                nodes.put(e[0], new ArrayList<>());  // Initialization
            nodes.get(e[0]).add(e[1]);
        }
        
        List<Integer> candi = new ArrayList<>();
        candi.add(0);  // ROOT
        
        DFS(0, 0, 0, candi, info);
        
        return answer;
    }
}
