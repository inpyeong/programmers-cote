#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> adj[n+1];
    for(auto e : edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> dist(n+1, 0);
    queue<int> q;
    
    int start = 1;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];
            if(there != start && !dist[there]) {
                q.push(there);
                dist[there] = dist[here] + 1;
            }
        }
    }
    int maxDist = *max_element(dist.begin(), dist.end()), answer = 0;
    for(int d : dist)
        if(d == maxDist) answer++;
    return answer;
}
