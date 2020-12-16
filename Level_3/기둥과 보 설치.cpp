#include <vector>

using namespace std;

bool gi[102][102] = {};
bool bo[102][102] = {};

bool checkGi(int x, int y) {
    if(y == 1) return true;
    if(gi[x][y-1]) return true;
    if(bo[x-1][y]) return true;
    if(bo[x][y]) return true;
    return false;
}

bool checkBo(int x, int y) {
    if(gi[x][y-1]) return true;
    if(gi[x+1][y-1]) return true;
    if(bo[x+1][y] && bo[x-1][y]) return true;
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

	for(int i = 0; i < build_frame.size(); ++i) {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        x++;
        y++;
        
        // 기둥 설치
        if(a == 0 && b == 1) {
            if(checkGi(x, y)) gi[x][y] = 1;
        }
        // 보 설치
        else if (a == 1 && b == 1) {
            if(checkBo(x, y)) bo[x][y] = 1;
        }
        // 기둥 삭제
        else if (a == 0 && b == 0) {
            bool ok = true;
            gi[x][y] = 0;
            
            if(gi[x][y+1] && !checkGi(x, y+1)) ok = false;
            else if(bo[x][y+1] && !checkBo(x, y+1)) ok = false;
            else if(bo[x-1][y+1] && y < n && !checkBo(x-1, y+1)) ok = false;
            
            if(!ok) gi[x][y] = 1;
        }
        // 보 삭제
        else if(a == 1 && b == 0){
            bool ok = true;
            bo[x][y] = 0;

            if(gi[x][y] && !checkGi(x, y)) ok = false;
            else if(gi[x+1][y] && !checkGi(x+1, y)) ok = false;
            else if(bo[x-1][y] && !checkBo(x-1, y)) ok = false;
            else if(bo[x+1][y] && !checkBo(x+1, y)) ok = false;
            
            if(!ok) bo[x][y] = 1;
        }
    }

	for(int i = 1; i <= n+1; ++i)
        for(int j = 1; j <= n+1; ++j) {
            if(gi[i][j]) answer.push_back({ i-1, j-1, 0 });
            if(bo[i][j]) answer.push_back({ i-1, j-1, 1 });
        }
    return answer;
}
