#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<bool> > adj(n+1, vector<bool>(n+1, false));
    for(auto r : results)
        adj[r[0]][r[1]] = true;
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(adj[i][k] && adj[k][j])
                    adj[i][j] = true;
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j = 1; j <= n; ++j) 
            if(adj[i][j] || adj[j][i]) cnt++;
        if(cnt == n-1) answer++;
    }
    return answer;
}
