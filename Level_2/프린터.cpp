#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max = *max_element(priorities.begin(), priorities.end());
    while(true) {
        if(priorities.front() < max) {
            priorities.push_back(priorities.front());
            priorities.erase(priorities.begin());
        }
        else {
            answer++;
            priorities.erase(priorities.begin());
            max = *max_element(priorities.begin(), priorities.end());
            if(location == 0) break;
        }
        location--;
        if(location < 0) location = priorities.size() - 1;
    }
    return answer;
}
