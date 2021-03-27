class Solution {
    class Trie {
        Trie[] child = new Trie[26];
        int count;
        int aletter = Character.getNumericValue('a');
        
        void insert(String str) {
            Trie curr = this;
            for (char ch : str.toCharArray()) {
                curr.count++;
                int idx = Character.getNumericValue(ch) - aletter;
                if (curr.child[idx] == null)
                    curr.child[idx] = new Trie();
                
                curr = curr.child[idx];
            }
            
            curr.count++;
        }
        
        int search(String str) {
            Trie curr = this;
            for (char ch : str.toCharArray()) {
                if (ch == '?') return curr.count;
                curr = curr.child[Character.getNumericValue(ch) - aletter];
                if (curr == null)
                    return 0;
            }
            
            return curr.count;
        }
    }
    
    Trie[] TrieRoot = new Trie[10000];
    Trie[] ReTrieRoot = new Trie[10000];
    
    public int[] solution(String[] words, String[] queries) {
        int[] answer = new int[queries.length];
        int ansIdx = 0;
        
        for (String str : words) {
            int idx = str.length() - 1;
            if (TrieRoot[idx] == null) {
                TrieRoot[idx] = new Trie();
                ReTrieRoot[idx] = new Trie();
            }
            
            TrieRoot[idx].insert(str);
            str = new StringBuilder(str).reverse().toString();
            ReTrieRoot[idx].insert(str);
        }
        
        for (String str : queries) {
            int idx = str.length() - 1;
            if (TrieRoot[idx] == null) {
                answer[ansIdx++] = 0;
            } else {
                if (str.charAt(0) != '?') {
                    answer[ansIdx++] = TrieRoot[idx].search(str);
                } else {
                    str = new StringBuilder(str).reverse().toString();
                    answer[ansIdx++] = ReTrieRoot[idx].search(str);
                }
            }
        }
        
        return answer;
    }
}
