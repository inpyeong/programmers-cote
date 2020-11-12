#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

bool comparePlayCnt(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<pair<int, int> > > genresPlayList;
    unordered_map<string, int> genresPlayCnt;
    vector<pair<string, int> > genresPlayCntValue;
    
    for(int i = 0; i < plays.size(); ++i) {
        genresPlayList[genres[i]].push_back(make_pair(plays[i], i));
        genresPlayCnt[genres[i]] += plays[i];
    }
    
    for(auto &k : genresPlayList)
        sort(k.second.begin(), k.second.end(), compare);
    
    genresPlayCntValue.assign(genresPlayCnt.begin(), genresPlayCnt.end());
    sort(genresPlayCntValue.begin(), genresPlayCntValue.end(), comparePlayCnt);
    
    vector<int> answer;
    for(int i = 0; i < genresPlayCntValue.size(); ++i) {
        string genresName = genresPlayCntValue[i].first;
        for(int j = 0; (j < genresPlayList[genresName].size()) && j < 2; ++j)
            answer.push_back(genresPlayList[genresName][j].second);
    }
    return answer;
}
