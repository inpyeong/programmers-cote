#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int time = 0, j = 0, answer = 0;
    priority_queue<pair<int, int> > pq;
    
    while(j < jobs.size() || !pq.empty()) {
        if(j < jobs.size() && time >= jobs[j][0]) {
            pq.push(make_pair(-jobs[j][1], jobs[j][0]));
            j++;
            continue;
        }
        if(!pq.empty()) {
            time += -pq.top().first;
            answer += (time - pq.top().second);
            pq.pop();
        }
        else
            time = jobs[j][0];
    }
    return answer / jobs.size();
}
