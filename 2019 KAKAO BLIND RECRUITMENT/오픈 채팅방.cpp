#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string> > ans;
    map<string, string> userList;
    stringstream ss;
    for(int i = 0; i < record.size(); ++i) {
        ss.str(record[i]);
        string cmd, uid, name;
        ss >> cmd >> uid >> name;
        if(name.size()) userList[uid] = name;
        if(cmd == "Enter")
            ans.push_back(make_pair("Enter", uid));
        else if(cmd == "Leave")
            ans.push_back(make_pair("Leave", uid));
        ss.clear();
    }
    for(int i = 0; i < ans.size(); ++i) {
        if(ans[i].first == "Enter")
            answer.push_back(userList[ans[i].second] + "님이 들어왔습니다.");
        else
            answer.push_back(userList[ans[i].second] + "님이 나갔습니다.");
    }
    return answer;
}
