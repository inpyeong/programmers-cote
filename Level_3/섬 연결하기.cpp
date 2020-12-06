#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100, INF = 987654321;
vector<pair<int, int> > adj[MAX_N];

struct DisJointSet {
    vector<int> parent, rank;
    DisJointSet(int V): parent(V), rank(V, 1) {
        for(int i = 0; i < V; ++i)
            parent[i] = i;
    }
    
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int kruskal(vector<pair<int, int> >& selected, int V) {
    int ret = 0;
    selected.clear();
    
    vector<pair<int, pair<int, int> > > edges;
    for(int u = 0; u < V; ++u)
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    sort(edges.begin(), edges.end());
    DisJointSet sets(V);
    
    for(int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}

int solution(int n, vector<vector<int>> costs) {
    
    for(int i = 0; i < costs.size(); ++i) {
        int a = costs[i][0], b = costs[i][1], c = costs[i][2];
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
    
    vector<pair<int, int> > selected;
    int answer = kruskal(selected, n);
    return answer;
}

