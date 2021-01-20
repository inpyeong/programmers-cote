#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countBits(int n) {
    int ret = 0;
    while(n) {
        if(n & 1) ret++;
        n = n >> 1;
    }
    return ret;
}

bool cmp(int a, int b) {
    int x = countBits(a), y = countBits(b);
    return x > y;
}


bool check(const vector<vector<string> >& relation, int rowSz, int colSz, int subset) {
    for(int a = 0; a < rowSz-1; ++a) {
        for(int b = a+1; b < rowSz; ++b) {
            bool isSame = true;
            for(int k = 0; k < colSz; ++k) {
                if((subset & 1 << k) == 0) continue;
                if(relation[a][k] != relation[b][k]) {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowSz = relation.size();
    int colSz = relation.front().size();
    vector<int> candidates;
    
    for(int i = 1; i < 1 << colSz; ++i)
        if(check(relation, rowSz, colSz, i))
            candidates.push_back(i);
    sort(candidates.begin(), candidates.end(), cmp);
    
    while(!candidates.empty()) {
        int n = candidates.back();
        candidates.pop_back();
        ++answer;
        for(auto it = candidates.begin(); it != candidates.end();) {
            if((n & *it) == n)
                it = candidates.erase(it);
            else it++;
        }
    }
    return answer;
}
