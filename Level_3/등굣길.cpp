#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int cache[101][101];

int memoized(int y, int x) {
    if(y == 0 || x == 0) return 0;
    if(y == 1 && x == 1) return 1;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = (memoized(y-1, x) % MOD + memoized(y, x-1) % MOD) % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(cache, -1, sizeof(cache));
    for(auto p : puddles)
        cache[p[1]][p[0]] = 0;
    return memoized(n, m);
}
