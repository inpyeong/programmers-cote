#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long answer, minTime = 1, maxTime, avgTime, human = 0;
    maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    
    while(minTime <= maxTime) {
        avgTime = (minTime + maxTime) / 2;
        for(auto t : times) human += (avgTime / t);
        if(n <= human) {
            answer = avgTime;
            maxTime = avgTime - 1;
        }
        else minTime = avgTime + 1;
        human = 0;
    }
    return answer;
}
