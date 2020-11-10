#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxCnt;

void dfs(string start, int cnt, vector<vector<string> >& tickets, vector<bool>& visited, vector<string>& answer, vector<string>& temp) {
    temp.push_back(start);
    if(maxCnt < cnt) {
        maxCnt = cnt;
        answer = temp;
    }
    for(int i = 0; i < tickets.size(); ++i)
        if(tickets[i][0] == start && !visited[i]) {
            visited[i] = true;
            dfs(tickets[i][1], cnt+1, tickets, visited, answer, temp);
            visited[i] = false;
        }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    vector<string> answer, temp;
    vector<bool> visited(tickets.size(), false);
    dfs("ICN", 0, tickets, visited, answer, temp);
    return answer;
}
