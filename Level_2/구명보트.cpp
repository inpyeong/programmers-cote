#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, cnt = 0, begin = 0, end = 0;
    // sort(people.begin(), people.end());
    // while(true) {
    //     int first = people[people.size() - end++];
    //     cnt++;
    //     if(limit - first >= people[begin]) {
    //         begin++;
    //         cnt++;
    //     }
    //     answer++;
    //     if(cnt >= people.size()) break;
    // }
    sort(people.begin(), people.end(), greater<int>());
    int n = people.size();
    for(int i = 0, j = n-1; i <= j; ++i) {
        if(people[i] + people[j] <= limit) j--;
        answer++;
    }
    return answer;
}
