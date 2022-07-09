import java.util.*;

class Solution {
    public int J(String str1, String str2) {
        List<String> s1 = new LinkedList<>();
        List<String> s2 = new LinkedList<>();
        List<String> l = new LinkedList<>();
        
        for (int i = 0; i < str1.length()-1; ++i) {
            if (str1.charAt(i) < 'a' || str1.charAt(i) > 'z') continue;
            if (str1.charAt(i+1) < 'a' || str1.charAt(i+1) > 'z') continue;
            
            s1.add(str1.charAt(i) + "" + str1.charAt(i+1));
        }
        
        for (int i = 0; i < str2.length()-1; ++i) {
            if (str2.charAt(i) < 'a' || str2.charAt(i) > 'z') continue;
            if (str2.charAt(i+1) < 'a' || str2.charAt(i+1) > 'z') continue;
            
            String s = str2.charAt(i) + "" + str2.charAt(i+1);
            
            if (!s1.remove(s)) {
                s2.add(s);
            } else {
                l.add(s);
            }
        }
        
        if (s1.size() == 0 && s2.size() == 0 && l.size() == 0)
            return 65536;
        
        int i = l.size(), u = s1.size() + s2.size() + l.size();
        return (i * 65536) / u;
    }
    
    public int solution(String str1, String str2) {
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        return J(str1, str2);
    }
}
