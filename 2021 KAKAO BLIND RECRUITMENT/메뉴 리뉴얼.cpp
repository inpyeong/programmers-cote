#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> list;
map<int, int> cntList;
map<string, int>::iterator listIt;
map<int, int>::iterator cntIt;


void dfs(string order, int idx, int sz, int cnt, string tmp) {
    tmp += order[idx];
    if(cnt == sz) {
        list[tmp]++;
        if(cntList[sz] < list[tmp])
            cntList[sz] = list[tmp];
        return;
    }
    for(int i = idx+1; i < order.size(); ++i)
        dfs(order, i, sz, cnt+1, tmp);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < course.size(); ++i) {
        int sz = course[i];
        for(int j = 0; j < orders.size(); ++j) {
            for(int k = 0; k < orders[j].size(); ++k) {
                sort(orders[j].begin(), orders[j].end());
                dfs(orders[j], k, sz, 1, "");
            }
        }
    }
    for(cntIt = cntList.begin(); cntIt != cntList.end(); ++cntIt) {
        cout << cntIt->first << " " << cntIt->second << endl;
        for(listIt = list.begin(); listIt != list.end(); ++listIt) {
            if(cntIt->second >= 2)
                if(listIt->first.size() == cntIt->first && listIt->second == cntIt->second)
                    answer.push_back(listIt->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
