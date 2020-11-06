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
