#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    // "시간:분"을 "분"으로만 단순화한다.
    vector<int> timetableToInt;
    for(string time : timetable) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        int temp = 0;
        temp += hour * 60;
        temp += minute;
        timetableToInt.push_back(temp);
    }
    sort(timetableToInt.begin(), timetableToInt.end());
    
    // time: 09:00부터 셔틀버스 운영 시작
    // idx: 셔틀버스에 처음으로 탑승할 크루의 인덱스 
    // mCnt: 셔틀버스 탑승 인원 수
    int time = 540, idx = 0, mCnt;
    for(int i = 0; i < n; ++i) {
        mCnt = 0;
        while(idx < timetableToInt.size() && timetableToInt[idx] <= time) {
            // 만약 최대 탑승 인원이 초과되면 탑승 불가
            if(mCnt >= m) break;
            mCnt++;
            idx++;
        }
        if(i < n-1) time += t;
    }
    string answer = "";
    int totalMinute = mCnt < m ? time : timetableToInt[idx-1]-1;
    string ansH = to_string(totalMinute / 60);
    if(ansH.size() == 1) ansH = "0" + ansH;
    string ansM = to_string(totalMinute % 60);
    if(ansM.size() == 1) ansM = "0" + ansM;
    answer = ansH + ":" + ansM;
    
    return answer;
}
