#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, 0};
    map<string, int> m;
    queue<string> q;
    for(string gem : gems)
        m[gem] = 1;
    int gemSize = m.size(), start = 0, end = 100001, tmp = 0;
    m.clear();
    
    for(int i = 0; i < gems.size(); ++i) {
        m[gems[i]]++;
        q.push(gems[i]);
        while(true) {
            if(m[q.front()] > 1) {
                m[q.front()]--;
                q.pop();
                tmp++;
            }
            else break;
        }
        if(m.size() == gemSize && end > q.size()) {
            start = tmp;
            end = q.size();
        }
    }
    answer[0] = start + 1;
    answer[1] = start + end;
    return answer;
}
