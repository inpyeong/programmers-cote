#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int cache[500][500];

int memoized(const vector<vector<int> >& triangle, int y, int x) {
    if(y == triangle.size() - 1)
        return triangle[y][x];
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int add = max(memoized(triangle, y+1, x), memoized(triangle, y+1, x+1));
    return ret = triangle[y][x] + add; 
}

int solution(vector<vector<int>> triangle) {
    memset(cache, -1, sizeof(cache));
    return memoized(triangle, 0, 0);
}
