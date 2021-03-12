#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    stringstream ss;
    vector<pair<int, int> > tasks;
    for(int i = 0; i < lines.size(); ++i) {
        string res, pro;
        string s;
        ss.str(lines[i]);
        for(int j = 0; j < 3; ++j) {
            ss >> s;
            if(j == 1) res = s;
            if(j == 2) pro = s;
        }
        ss.clear();
        int hour = stoi(res.substr(0, 2));
        int minute = stoi(res.substr(3, 2));
        int sec = stoi(res.substr(6, 2));
        int mili =  stoi(res.substr(9, 3));
        int process = stof(pro.substr(0, pro.size()-1)) * 1000;
        int resTime = (hour * 3600000) + (minute * 60000) + (sec * 1000) + mili;
        int reqTime = resTime - process + 1;
        tasks.push_back(make_pair(reqTime, resTime));
    }
    for(int i = 0; i < tasks.size(); ++i) {
        int end = tasks[i].second;
        int _end = end + 1000;
        int cnt = 0;
        for(int j = i; j < tasks.size(); ++j)
            if(tasks[j].first < _end) cnt++;
        answer = max(answer, cnt);
    }
    return answer;
}
