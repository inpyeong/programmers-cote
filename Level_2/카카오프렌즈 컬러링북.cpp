#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool discovered[100][100];
int M, N;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int BFS(const vector<vector<int> >& picture, int y, int x) {
    queue<pair<int, int> > Q;
    discovered[y][x] = true;
    Q.push(make_pair(y, x));
    
    int color = picture[y][x];
    int ret = 1;
    while(!Q.empty()) {
        int hereY = Q.front().first;
        int hereX = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++i) {
            int thereY = hereY + dy[i];
            int thereX = hereX + dx[i];
            if(thereY < 0 || thereY >= M || thereX < 0 || thereX >= N) continue;
            if(color == picture[thereY][thereX] && !discovered[thereY][thereX]) {
                discovered[thereY][thereX] = true;
                Q.push(make_pair(thereY, thereX));
                ret++;
            }
        }
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            discovered[i][j] = false;
    M = m;
    N = n;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int y = 0; y < m; ++y)
        for(int x = 0; x < n; ++x) {
            if(picture[y][x] && !discovered[y][x]) {
                max_size_of_one_area = max(max_size_of_one_area, BFS(picture, y, x));
                number_of_area++;
            }
        }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
