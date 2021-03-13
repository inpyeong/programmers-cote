#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    for(int i = 0; i < 26; ++i)
        m[string(1, 'A'+i)] = i+1;
    string str = "";
    for(int i = 0; i < msg.size(); ++i) {
        str += msg[i];
        if(m.find(str) != m.end()) {
            if(i == msg.size()-1) {
                answer.push_back(m[str]);
                break;
            }
            continue;
        }
        m[str] = m.size()+1;
        str.pop_back();
        answer.push_back(m[str]);
        str.clear();
        i--;
    }
    return answer;
}
