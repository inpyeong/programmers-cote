#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int answer = 1, cPos = routes[0][1];
    for(int i = 1; i < routes.size(); ++i) {
        if(cPos > routes[i][1])
            cPos = routes[i][1];
        if(cPos < routes[i][0]) {
            answer++;
            cPos = routes[i][1];
        }
    }
    return answer;
}
