import java.util.*;

class Solution {
    static final int MAX_USER_ID_LENGTH = 8;
    
    String[] User_id, Banned_id;
    boolean[] check = new boolean[MAX_USER_ID_LENGTH];
    Set<Integer> mySet = new HashSet<>();
    
    void findUserIdList(int index, int candidate) {
     	if(index == Banned_id.length) {
            mySet.add(candidate);
            return;
        }   
        for(int i = 0; i < User_id.length; ++i) {
            if(User_id[i].length() != Banned_id[index].length())
                continue;
            if(check[i] == true)
                continue;
            int j;
            for(j = 0; j < User_id[i].length(); ++j) {
                if(Banned_id[index].charAt(j) == '*')
                    continue;
                if(User_id[i].charAt(j) != Banned_id[index].charAt(j))
                    break;
            }
            if(j == User_id[i].length()) {
                check[i] = true;
                findUserIdList(index+1, candidate | (1 << i));
                check[i] = false;
            }
        }
    }
    
    public int solution(String[] user_id, String[] banned_id) {
        User_id = user_id;
        Banned_id = banned_id;
        
        findUserIdList(0, 0);
        
        return mySet.size();
    }
}
