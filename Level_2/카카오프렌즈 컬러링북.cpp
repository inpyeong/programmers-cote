#include <vector>
#include <queue>

using namespace std;

int dy[] = { 1, 0, -1,  0 };
int dx[] = { 0, 1,  0, -1 };

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int, int> > q;
    vector<vector<bool> > discovered(m, vector<bool>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!picture[i][j] || discovered[i][j]) continue;
            number_of_area++;
            int size_of_one_area = 0;
            q.push(make_pair(i, j));
            discovered[i][j] = true;
            while(!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                size_of_one_area++;
                for(int k = 0; k < 4; ++k) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(ny >= 0 && ny < m && nx >= 0 && nx < n) {
                        if(picture[ny][nx] == picture[y][x] && !discovered[ny][nx]) {
                            q.push(make_pair(ny, nx));
                            discovered[ny][nx] = true;
                        }
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
