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
    int _a = countBits(a);
    int _b = countBits(b);
    return a > b;
}

bool check(const vector<vector<string> >& relation, int rowSz, int colSz, int subset) {
    for(int a = 0; a < rowSz-1; ++a) {
        for(int b = a+1; b < rowSz; ++b) {
            bool isSame = true;
            for(int k = 0; k < colSz; ++k) {
                if((1 << k & subset) == 0) continue;
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
    vector<int> candidate;
    for(int i = 1; i < (1 << colSz); ++i)
        if(check(relation, rowSz, colSz, i))
            candidate.push_back(i);
    sort(candidate.begin(), candidate.end(), cmp);
    while(!candidate.empty()) {
        int k = candidate.back();
        candidate.pop_back();
        answer++;
        for(auto it = candidate.begin(); it != candidate.end();) {
            if((k & *it) == k)
                it = candidate.erase(it);
            else it++;
        }
    }
    return answer;
}
