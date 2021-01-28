#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land) {
    for(int i = 1; i < land.size(); ++i)
        for(int j = 0; j < 4; ++j) 
            land[i][j] += max(land[i-1][(j+1)%4], max(land[i-1][(j+2)%4], land[i-1][(j+3)%4]));
    return max(land[land.size()-1][0], max(land[land.size()-1][1], max(land[land.size()-1][2], land[land.size()-1][3])));
}
