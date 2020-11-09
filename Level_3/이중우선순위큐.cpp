#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    int size = operations.size(), sNum = 0;
    vector<bool> v;
    priority_queue<pair<int, int> > maxPq, minPq;
    
    for(string operation : operations) {
        char cmdC = operation.at(0);
        int cmdN = stoi(operation.substr(2));
        
        if(cmdC == 'I') {
            cout << "sNum: " << sNum << endl; 
            maxPq.push(make_pair(cmdN, sNum));
            minPq.push(make_pair(-cmdN, sNum));
            v.push_back(true);
            sNum++;
        }
        if(cmdC == 'D') {
            if(cmdN == 1) {
                while(!maxPq.empty()) {
                    int _sNum = maxPq.top().second;
                    maxPq.pop();
                    if(!v[_sNum]) continue;
                    else {
                        v[_sNum] = false;
                        break;
                    }
                }
            }
            if(cmdN == -1) {
                while(!minPq.empty()) {
                    int _sNum = minPq.top().second;
                    minPq.pop();
                    if(!v[_sNum]) continue;
                    else {
                        v[_sNum] = false;
                        break;
                    }
                }
            }
        }
    }
    for(auto value : v) {
        cout << value << " ";
    }
    vector<int> answer;
    while(!maxPq.empty()) {
        int _sNum = maxPq.top().second;
        int _cmdN = maxPq.top().first;
        maxPq.pop();
        if(v[_sNum]) {
            answer.push_back(_cmdN);
            break;
        }
    }
    while(!minPq.empty()) {
        int _sNum = minPq.top().second;
        int _cmdN = -minPq.top().first;
        minPq.pop();
        if(v[_sNum]) {
            answer.push_back(_cmdN);
            break;
        }
    }
    if(!answer.size()) {
        answer.push_back(0);
        answer.push_back(0);
    } 
    return answer;
}
