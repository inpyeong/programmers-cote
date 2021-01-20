#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    // { act, userid }
    vector<pair<string, string> > _answer;
    // { userid, nickname }
    map<string, string> users;
    stringstream ss;
    string sstr;
    for(int i = 0; i < record.size(); ++i) {
        string act, userid, nickname;
        ss.str(record[i]);
        int cnt = 0;
        while(ss >> sstr) {
            switch(cnt) {
                case 0:
                    act = sstr;
                    break;
                case 1:
                    userid = sstr;
                    break;
                case 2:
                    nickname = sstr;
                    break;
            }
            cnt++;
        }
        ss.clear();
        if(act != "Change")
            _answer.push_back(make_pair(act, userid));
        // 입장
        if(act == "Enter" || act == "Change") {
            // 유저 등록 또는 변경된 닉네임 저장
            users[userid] = nickname;
        }
    }
    for(auto a : _answer) {
        string nn = users[a.second];
        if(a.first == "Enter") answer.push_back(nn + "님이 들어왔습니다.");
        else answer.push_back(nn + "님이 나갔습니다.");
    }
    return answer;
}
