import java.util.*;

class Solution {
    List<List<Integer> > adj = new ArrayList<>();
    Queue<Integer> q = new LinkedList<>();
    int[] prior, hang;
    boolean[] visited;
    
    public boolean solution(int n, int[][] path, int[][] order) {
        for(int i = 0; i < n; ++i)
            adj.add(new ArrayList<>());
        visited = new boolean[n];
        prior = new int[n];
        hang = new int[n];
        
        // 인접 리스트 생성
        for(int[] p : path) {
            adj.get(p[0]).add(p[1]);
            adj.get(p[1]).add(p[0]);
        }
        // prior 배열 채우기.
        for(int[] o : order) 
            prior[o[1]] = o[0];
        
        // 0번 정점을 방문하기 전에 미리 방문해야 할 정점이 있다면 불가능
        if(prior[0] > 0)
            return false;
        
        // bfs 시작, 0번 정점 방문
        visited[0] = true;
        for(int v : adj.get(0))
            q.add(v);
        while(!q.isEmpty()) {
            int here = q.remove();
            // 방문했던 정점이라면 탐색하지 않는다.
            if(visited[here] == true)
                continue;
            // 미리 방문해야만 하는 정점을 방문하지 못했다면 hang에 기록한 후 일단 넘어간다.
            if(visited[prior[here]] == false) {
                hang[prior[here]] = here;
                continue;
            }
            
            // e 정점을 방문한다.
            visited[here] = true;
            // e 정점과 연결된 정점들을 큐에 넣는다.
            for(int there : adj.get(here))
                q.add(there);
            // e 정점을 방문하면 이제 방문 가능한 정점을 큐에 넣는다.
            q.add(hang[here]);
        }
        
        for(int i = 0; i < n; ++i)
            if(visited[i] == false)
                return false;
        return true;
    }
}
