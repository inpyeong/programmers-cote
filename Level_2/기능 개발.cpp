#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    int sz = progresses.size();
    for(int i = 0; i < sz; ++i) {
        int left = 100 - progresses[i];
        int day = left / speeds[i];
        if(left % speeds[i]) day++;
        days.push(day);
    }
    int ans = 1;
    int s = days.front();
    days.pop();
    while(true) {
        int tmp = days.front();
        days.pop();
        if(s >= tmp) ans++;
        else {
            answer.push_back(ans);
            ans = 1;
            s = tmp;
        }
        if(days.empty()) {
            answer.push_back(ans);
            break;
        }
    }
    return answer;
}
