#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int i, int j) {
    return i > j;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > adj(n + 1, vector<int>(n + 1, 0));
    vector<int> discovered(n + 1, -1);
    queue<int> q;
    
    for(int i = 0; i < edge.size(); ++i) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][v] = adj[v][u] = 1;
    }
    
    q.push(1);
    discovered[1] = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int there = 1; there <= adj.size(); ++there) {
            if(adj[here][there] && discovered[there] == -1) {
                q.push(there);
                discovered[there] = discovered[here] + 1;
            }
        }
    }
    
    sort(discovered.begin(), discovered.end(), cmp);
    int maxDistance = discovered[0], answer = 0;
    for(int i = 0; i < n; ++i) {
      	if(discovered[i] == maxDistance)
            answer++;
        else break;
    }
    return answer;
}
