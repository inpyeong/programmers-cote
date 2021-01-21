#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, curWeight = 0, truckOut = 0;
    // weight, time
    queue<pair<int, int> > bridge;
    while(true) {
        if(answer - bridge.front().second == bridge_length) {
            curWeight -= bridge.front().first;
            bridge.pop();
            truckOut++;
        }
        if(truck_weights.size() > 0 && truck_weights.front() + curWeight <= weight) {
            curWeight += truck_weights.front();
            bridge.push(make_pair(truck_weights.front(), answer));
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(bridge.empty()) break;
    }
    return answer;
}
