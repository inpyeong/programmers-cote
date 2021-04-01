#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {-1, 1,  0, 0};
int dx[] = { 0, 0, -1, 1};

int bfs(pair<int, int> src, pair<int, int> target) {
    queue<pair<int, int> > q;
    vector<vector<int> > discovered(4, vector<int>(3, 0)); 
    q.push(src);
    discovered[src.first][src.second] = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == target.first && x == target.second)
            return discovered[y][x];
        for(int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= 4 || nx < 0 || nx >= 3) continue;
            if(discovered[ny][nx] == 0) {
                discovered[ny][nx] = discovered[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return 0;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = { 3, 0 };
    pair<int, int> right = { 3, 2 };
    for(int num : numbers) {
        if(num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left = { num/3, 0 };
        }
        else if(num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right = { num/3-1, 2 };
        }
        else {
            pair<int, int> target;
            if(num == 0) target = { 3, 1 };
            else target = { num/3, 1 };
            int distl = bfs(left, target);
            int distr = bfs(right, target);
            if(distl == distr) {
                if(hand == "right") {
                    answer += 'R';
                    right = target;
                }
                else {
                    answer += 'L';
                    left = target;
                }
            }
            else if(distl > distr) {
                answer += 'R';
                right = target;
            }
            else {
                answer += 'L';
                left = target;
            }
        }
    }
    return answer;
}
