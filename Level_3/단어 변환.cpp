// bfs
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> q;
vector<int> discovered(50, 0);

int solution(string begin, string target, vector<string> words) {

    for(int i = 0; i < words.size(); ++i) {
        int cnt = 0;
        for(int j = 0; j < words[i].size(); ++j) {
            if(begin[j] != words[i][j]) cnt++;
            if(cnt == 2) break;
        }
        if(cnt == 1) {
            q.push(i);
            discovered[i] = 1;
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        string nowStr = words[now];
        if(nowStr == target) return discovered[now];
        for(int next = 0; next < words.size(); ++next) {
            string nextStr = words[next];
            int cnt = 0;
            for(int j = 0; j < nextStr.size(); ++j) {
                if(nowStr[j] != nextStr[j]) cnt++;
                if(cnt == 2) break;
            }
            if(cnt == 1 && !discovered[next]) {
                q.push(next);
                discovered[next] = discovered[now] + 1;
            }
        }
    }
    return 0;
}

// dfs
#include <string>
#include <vector>

using namespace std;

int answer = 100;

bool isAdjcent(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a.at(i) != b.at(i)) cnt++;
        if(cnt == 2) return false;
    }
    return true;
}

void dfs(string begin, string target, const vector<string>& words, vector<bool>& used, int cnt) {
    for(int i = 0; i < words.size(); ++i) {
        if(isAdjcent(begin, words[i]) && !used[i]) {
            if(words[i] == target) {
                answer = min(answer, cnt+1);
                return;
            }
            used[i] = true;
            dfs(words[i], target, words, used, cnt+1);
            used[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> used(words.size(), false);
    dfs(begin, target, words, used, 0);
    if(answer == 100) return 0;
    return answer;
}
