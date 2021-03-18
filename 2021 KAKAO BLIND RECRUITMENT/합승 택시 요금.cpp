#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int adj[n+1][n+1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j) {
        	if(i == j) adj[i][j] = 0;	    
            else adj[i][j] = INF;
        }
    for(int i = 0; i < fares.size(); ++i) {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];
      	adj[c][d] = f;
        adj[d][c] = f;
    }
    for(int k = 1; k <= n; ++k) 
        for(int i = 1; i <= n; ++i) 
            for(int j = 1; j <= n; ++j) 
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
    int answer = INF;
    for(int i = 1; i <= n; ++i) {
        if(adj[s][i] == INF || adj[i][a] == INF || adj[i][b] == INF) continue;
        int cost = adj[s][i];
        cost += adj[i][a];
        cost += adj[i][b];
        answer = min(answer, cost);
    }
    return answer;
}
