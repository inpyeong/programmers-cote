import java.util.*;

class Solution {
    static final int mxN = 200000;
    List<Integer>[] edges = new ArrayList[mxN];
    int[] prior = new int[mxN];
    int[] hang = new int[mxN];
    boolean[] visited = new boolean[mxN];
    
    void dfs(int v) {
        if(visited[v] == true) return;
        
        if(visited[prior[v]] == false) {
            hang[prior[v]] = v;
            return;
        }
        
        visited[v] = true;
        dfs(hang[v]);
        for(int i = 0; i < edges[v].size(); ++i)
            dfs(edges[v].get(i));
    }
    
    public boolean solution(int n, int[][] path, int[][] order) {
        for(int i = 0; i < n; ++i)
            edges[i] = new ArrayList<>();
        for(int[] p : path) {
            edges[p[0]].add(p[1]);
            edges[p[1]].add(p[0]);
        }
        for(int[] o : order) 
            prior[o[1]] = o[0];
        
        if(prior[0] > 0) return false;
        
        visited[0] = true;
        for(int i = 0; i < edges[0].size(); ++i)
            dfs(edges[0].get(i));
        
        for(int i = 0; i < n; ++i)
            if(!visited[i]) return false;
        return true;
    }
}
