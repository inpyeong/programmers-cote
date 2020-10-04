#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void fromTmpToList(queue<pair<int, int>>& list, vector<pair<int, int>>& tmp) {
    for(int i = 0; i < tmp.size(); ++i)
        list.push(tmp[i]);
    tmp.clear();
}

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> list;
    for(int i = 0; i < priorities.size(); ++i) 
        list.push(make_pair(i, priorities[i]));

    int answer = 0;
    vector<pair<int, int>> tmp;

    while(true) {
        bool check = true;
        pair<int, int> firstElement = list.front();
        list.pop();
        while(!list.empty()) {
            if(firstElement.second < list.front().second) {
                check = false;
                break;
            }
            else {
                tmp.push_back(list.front());
                list.pop();
            }
        }
        if(check) {
            ++answer;
            if (firstElement.first == location) return answer;
            fromTmpToList(list, tmp);
        }        
        else {
            while(!list.empty()) {
                tmp.push_back(list.front());
                list.pop();
            }
            fromTmpToList(list, tmp);
            list.push(firstElement);
        }
    }
}
