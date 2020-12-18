#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;
int len;
bool check[8];

void dfs(const vector<string>& u_id, const vector<string>& b_id, int i, int num) {
    if(i == len) {
        // set으로 중복된 케이스 제거.
        s.emplace(num);
        return;
    }
    
    for(int j = 0; j < u_id.size(); ++j) {
        int z;
        // 매칭이 안되면 건너뜀.
        if(u_id[j].size() != b_id[i].size()) continue;
        // 매칭됐던 아이디면 건너뜀.
        if(check[j]) continue;
        for(z = 0; z < u_id[j].size(); ++z) {
            if(b_id[i][z] == '*') continue;
            if(u_id[j][z] != b_id[i][z]) break;
        }
        
        // 매칭되면 DFS
        if(z == u_id[j].size()) {
            check[j] = true;
            // 비트 연산
            dfs(u_id, b_id, i+1, num | (1 << j));
            check[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    len = banned_id.size();
    dfs(user_id, banned_id, 0, 0);
    return s.size();
}
