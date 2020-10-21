#include <string>
#include <vector>

using namespace std;
bool visited[200];

void dfs(int n, vector<vector<int> >& computers, int here, int component) {
    visited[here] = true;
    for(int there = 0; there < n; ++there)
        if(computers[here][there] && !visited[there])
            dfs(n, computers, there, component);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; ++i)
        if(!visited[i]) dfs(n, computers, i, answer++);
    return answer;
}
