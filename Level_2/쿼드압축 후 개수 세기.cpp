#include <string>
#include <vector>

using namespace std;

vector<vector<int> > map;

void dfs(int y, int x, int size, vector<int>& answer) {
    bool zero, one;
    zero = one = true;
    for(int i = y; i < y+size; ++i)
        for(int j = x; j < x+size; ++j) {
            if(map[i][j] == 1) zero = false;
            if(map[i][j] == 0) one = false;
        }
    if(zero) {
        answer[0]++;
        return;
    }
    if(one) {
        answer[1]++;
        return;
    }
    dfs(y, x, size/2, answer);
    dfs(y, x+size/2, size/2, answer);
    dfs(y+size/2, x, size/2, answer);
    dfs(y+size/2, x+size/2, size/2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;
    dfs(0, 0, arr.size(), answer);
    return answer;
}
