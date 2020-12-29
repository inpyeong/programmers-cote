#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int solution(int N, vector<vector<int> > road, int K) {
    vector<pair<int, int> > adj[N+1];
    for(int i = 0; i < road.size(); ++i) {
        adj[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        adj[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    } 
    priority_queue<pair<int, int> > pq;
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int newCost = cost + adj[here][i].second;
            if(dist[there] > newCost) {
                dist[there] = newCost;
                pq.push(make_pair(-newCost, there));
            }
        }
    }
    int answer = 0;
    for(int i = 1; i < dist.size(); ++i)
        if(dist[i] <= K) answer++;
    return answer;
}
