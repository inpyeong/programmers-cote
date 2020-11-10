#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 1000000007;
int cache[101][101];

int memoized(int y, int x, const vector<vector<int> >& map) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    if(y < 1 || x < 1) return 0;
    if(y == 1 && x == 1) 
        return ret = 1;
    if(map[y][x] == -1)
        return ret = 0;
    return ret = ((memoized(y, x-1, map)) % INF + (memoized(y-1, x, map)) % INF) % INF;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(cache, -1, sizeof(cache));
    vector<vector<int> > map(101, vector<int>(101, 0));
    for(auto p : puddles)
        map[p[1]][p[0]] = -1;
    return memoized(n, m, map);
}
