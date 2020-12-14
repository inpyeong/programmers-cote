#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int time = 1;
    stack<pair<int, int> > s;
    vector<int> answer(prices.size(), 0);
    for(int i = 0; i < prices.size(); ++i) {
        while(!s.empty() && s.top().first > prices[i]) {
            answer[s.top().second-1] = time - s.top().second;
            s.pop();
        }
        s.push(make_pair(prices[i], i+1));
        time++;
    }
    time--;
    while(!s.empty()) {
        answer[s.top().second-1] = time - s.top().second;
        s.pop();
    }
    return answer;
}
