#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<long, long> , long> a, pair<pair<long, long> , long> b) {
    long long _a = a.first.first * b.first.second;
    long long _b = b.first.first * a.first.second;
    if(_a == _b) return a.second < b.second;
    return _a > _b;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<pair<long, long> , long> > ans;
    sort(stages.begin(), stages.end());
    int level = 1, notClear = 0, i;
    for(i = 0; i < stages.size();) {
        if(level > N) break;
        if(stages[i] == level) {
            notClear++;
            i++;
        }
        else if(stages[i] > level) {
            ans.push_back(make_pair(make_pair(notClear, notClear + stages.size() - i), level++));        
            notClear = 0;
        }
    }
    while(ans.size() < N) {
        ans.push_back(make_pair(make_pair(notClear, notClear + stages.size() - i), level++));        
        notClear = 0;
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); ++i) {
        answer.push_back(ans[i].second);
    }
    return answer;
}
