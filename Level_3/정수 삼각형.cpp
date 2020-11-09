#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int cache[500][500];

int memoized(const vector<vector<int>>& triangle, int y, int x) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;

    if(y == triangle.size()-1) return triangle[y][x];

    int left = memoized(triangle, y+1, x);
    int right = memoized(triangle, y+1, x+1);

    int bigger = left > right ? left : right;

    return ret = triangle[y][x] + bigger;
}

int solution(vector<vector<int>> triangle) {
    memset(cache, -1, sizeof(cache));
    int answer = memoized(triangle, 0, 0);
    return answer;
}
