#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int curTime = 0, curWeight = 0, curTruckIdx = 0;
    int numOfTrucks = truck_weights.size();
    vector<pair<bool, int> > truck(numOfTrucks, make_pair(false, 0));
    queue<int> bridge;
    
    while(true) {
        if(curTruckIdx < numOfTrucks && curWeight + truck_weights[curTruckIdx] <= weight) {
            curWeight += truck_weights[curTruckIdx];
            bridge.push(curTruckIdx);
            truck[curTruckIdx].first = true;
            curTruckIdx++;
        }
        curTime++;
        for(int i = 0; i < curTruckIdx; ++i) {
            if(truck[i].first) {
                truck[i].second++;
                if(truck[i].second == bridge_length) {
                    truck[i].first = false;
                    bridge.pop();
                    curWeight -= truck_weights[i];
                    continue;
                }
            }
        }
        if(bridge.empty() && curTruckIdx == numOfTrucks)
            break;
    }
    return ++curTime;
}
