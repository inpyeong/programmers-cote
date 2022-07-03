import java.util.*;

class Solution {
    
    static final char LEFT = '(';
    static final char RIGHT = ')';
    
    Stack<Character> Stack = new Stack<>();
    
    public boolean isGood(String w) {
        for (int i = 0; i < w.length(); ++i) {
            char c = w.charAt(i);
            
            if (c == LEFT) {
                Stack.push(c);
            }
            else if (c == RIGHT) {
                if (Stack.isEmpty()) 
                    return false;
                
                if (Stack.peek() == LEFT) {
                    Stack.pop();
                }
                else {
                    return false;
                }
            }
        }    
        return Stack.isEmpty();
    }
    
    public String go(String w) {
        if (w.length() == 0) 
            return "";
        
        String u = "", v = "";
        
        int lCnt = 0, rCnt = 0;
        for (int i = 0; i < w.length(); ++i) {
            char c = w.charAt(i);
            
            if (c == LEFT)
                lCnt++;
            else if (c == RIGHT)
                rCnt++;
            
            if (lCnt == rCnt) {
                u = w.substring(0, lCnt + rCnt);
                v = w.substring(lCnt + rCnt);
                break;
            }
        }
        
        if (isGood(u)) {
            return u + go(v);
        }
        else {
            String tmp = "(";
            tmp += go(v);
            tmp += ")";
            u = u.substring(1, u.length() - 1);
            String tmp2 = "";
            for (int i = 0; i < u.length(); ++i) {
                char c = u.charAt(i);
                if (c == LEFT) tmp2 += RIGHT;
                else tmp2 += LEFT;
            }
            tmp += tmp2;
            return tmp;
        }    
    }
    
    public String solution(String p) {
        return go(p);
    }
}
