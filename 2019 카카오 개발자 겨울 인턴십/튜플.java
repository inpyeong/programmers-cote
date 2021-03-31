import java.util.*;

class Solution {
    public int[] solution(String s) {
        s = s.substring(1, s.length()-1);
        
        int posl = 0, posr = 0;
        List<List<String>> subset = new ArrayList<>();
        for(int i = 0; i < s.length(); ++i) {
       		if(s.charAt(i) == '{') 
                posl = i;
            if(s.charAt(i) == '}') {
                posr = i;
                subset.add(Arrays.asList(s.substring(posl+1, posr).split(",") ));
            }
        }
        
        Collections.sort(subset, (a, b) -> {
            if(a.size() < b.size()) return -1;
            else return 1;
        });
        
        boolean[] check = new boolean[100001];
        List<Integer> answerList = new ArrayList<>();
        for(int i = 0; i < subset.size(); ++i) {
            for(int j = 0; j < subset.get(i).size(); ++j) {
                int num = Integer.parseInt(subset.get(i).get(j));
                if(check[num] == false) {
                    answerList.add(num);
                    check[num] = true;
                }
            }
        }
        int[] answer = new int[answerList.size()];
        for(int i = 0; i < answerList.size(); ++i) 
            answer[i] = answerList.get(i);
        return answer;
    }
}
