#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100, INF = 987654321;

int solution(int n, vector<vector<int>> costs) {
    vector<pair<int, int> > adj[MAX_N];
    priority_queue<pair<int, int> > pq;
    vector<int> dist(MAX_N, INF);
    
    for(auto c : costs) {
        adj[c[0]].push_back(make_pair(c[1], c[2]));
        adj[c[1]].push_back(make_pair(c[0], c[2]));
    }
    
    vector<vector<int> > usedEdge(n, vector<int>(n, 0));
    
    // start 0
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > dist[here]) continue;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int newDist = cost + adj[here][i].second;
            if(dist[there] > newDist) {
                usedEdge[here][there] = adj[here][i].second;
                dist[there] = newDist;
                pq.push(make_pair(-newDist, there));
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j) {
            if(usedEdge[i][j]) answer += usedEdge[i][j];
        }
    return answer;
}
