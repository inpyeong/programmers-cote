#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5;
bool visited[MAX];
int prior[MAX], hang[MAX];
vector<int> edge[MAX];

void dfs(int v){
    if(visited[v])return;
    
    if(!visited[prior[v]]){		
        hang[prior[v]] = v;
        return;
    }
 
    visited[v]=true;
    dfs(hang[v]);		
    for(int u : edge[v]) dfs(u);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto &a : path){
        edge[a[0]].push_back(a[1]);
        edge[a[1]].push_back(a[0]);
    }
    for(auto &a : order) prior[a[1]] = a[0];

    if(prior[0]) return false;

    visited[0] = true;
    for(int u : edge[0]) dfs(u);
    
    for(int i = 0;i < n; ++i) if(!visited[i]) return false;
    return true;
}
