import java.util.*;

class Solution {
    long answer = Long.MIN_VALUE;
    
    List<Long> numList = new ArrayList<>();
    List<String> operList = new ArrayList<>();
    
    String[] oper = { "+", "-", "*" };
    String[] output = new String[3];
    boolean[] visited = new boolean[3];
    
    long cal(long n1, long n2, String o) {
        long res = 0;
        switch(o) {
            case "+":
                res = n1 + n2;
             	break;
            case "-":
                res = n1 - n2;
             	break;
            case "*":
                res = n1 * n2;
             	break;
        }
        return res;
    }
    
    void solve() {
        List<String> oper = new ArrayList<>();
        oper.addAll(operList);
        
        List<Long> num = new ArrayList<>();
        num.addAll(numList);
        
        for(int i = 0; i < output.length; ++i) {
            String curOper = output[i];
            for(int j = 0; j < oper.size(); ++j) {
                if(oper.get(j).equals(curOper)) {
                    long n1 = num.get(j);
                    long n2 = num.get(j+1);
                    long res = cal(n1, n2, curOper);
                    
                    num.remove(j+1);
                    num.remove(j);
                    oper.remove(j);
                    
                    num.add(j, res);
                    j--;
                }
            }
        }
        answer = Math.max(answer, Math.abs(num.get(0)));
    }
    
    void per(int depth, int r) {
        if(depth == r) {
            solve();
            return;
        }
        
        for(int i = 0; i < oper.length; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                output[depth] = oper[i];
                per(depth+1, r);
                visited[i] = false;
            }
        }
    }
    
    public long solution(String expression) {
        String n = "";
        for(int i = 0; i < expression.length(); ++i) {
            char exp = expression.charAt(i);
            if(exp == '+' || exp == '-' || exp == '*') {
                operList.add(exp + "");
                numList.add(Long.parseLong(n));
                n = "";
            }
            else n += exp;
        }
        numList.add(Long.parseLong(n));
        per(0, oper.length);
        return answer;
    }
}
