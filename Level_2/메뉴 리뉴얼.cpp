#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> list;

void dfs(string order, int sz, int idx, string tmp) {
    tmp += order[idx];
    if(tmp.length() == sz) {
        list[tmp]++;
        return;
    }
    for(int i = idx+1; i < order.length(); ++i) 
        dfs(order, sz, i, tmp);
}

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end());
    for(int i = 0; i < course.size(); ++i) {
        list.clear();
        for(int j = 0; j < orders.size(); ++j) {
            for(int k = 0; k < orders[j].size(); ++k)
                dfs(orders[j], course[i], k, "");
        }
        vector<pair<string, int> > v;
        v.assign(list.begin(), list.end());
        sort(v.begin(), v.end(), cmp);
        if(v.size() && v[0].second >= 2) {
            answer.push_back(v[0].first);
            for(int j = 1; j < v.size(); ++j) {
                if(v[0].second == v[j].second) 
                    answer.push_back(v[j].first); 
                else break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
