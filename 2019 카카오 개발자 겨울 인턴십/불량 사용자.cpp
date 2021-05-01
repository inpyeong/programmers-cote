#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

const int MAX_USER_ID_LENGTH = 8;

set<int> s;
bool check[MAX_USER_ID_LENGTH];

void dfs(const vector<string>& user_id, const vector<string>& banned_id, int idx, int candi) {
    if(idx == banned_id.size()) {
        s.insert(candi);
        return;
    }
    for(int i = 0; i < user_id.size(); ++i) {
        if(user_id[i].size() != banned_id[idx].size())
            continue;
        if(check[i] == true)
            continue;
        int j;
        for(j = 0; j < user_id[i].size(); ++j) {
            if(banned_id[idx][j] == '*')
                continue;
            if(user_id[i][j] != banned_id[idx][j])
                break;
        }
        if(j == user_id[i].size()) {
            check[i] = true;
            dfs(user_id, banned_id, idx+1, candi | (1 << i));
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}
