#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    vector<int> startTimes, endTimes;
    for(int i = 0; i < lines.size(); ++i) {
        int h, m, s, ms, process;
        int startTime, endTime;
        lines[i].pop_back();
        h = stoi(lines[i].substr(11, 2)) * 3600 * 1000;
        m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
        s = stoi(lines[i].substr(17, 2)) * 1000;
        ms = stoi(lines[i].substr(20, 3));
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        endTime = h + m + s + ms;
        startTime = endTime - process + 1;
        
        startTimes.push_back(startTime);
        endTimes.push_back(endTime);
    }
    int answer = 0;
    for(int i = 0; i < lines.size(); ++i) {
        int _endTime = endTimes[i] + 1000, cnt = 0;
        for(int j = i; j < lines.size(); ++j) 
            if(startTimes[j] < _endTime) cnt++;
        if(answer < cnt) answer = cnt;
    }
    return answer;
}
