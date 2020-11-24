#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    vector<int> pq;
    vector<int>::iterator iter;
    
    for(auto operation : operations) {
        string command = operation.substr(0, 1);
        int value = stoi(operation.substr(2));
        
        if(command == "I")
            pq.push_back(value);
        if(command == "D") {
            if(pq.empty()) continue;
            if(value == 1)
                iter = max_element(pq.begin(), pq.end());
            else
                iter = min_element(pq.begin(), pq.end());
            pq.erase(iter);
        }
    }
    
    vector<int> answer;
	if(pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }    
    else {
        answer.push_back(*max_element(pq.begin(), pq.end()));
        answer.push_back(*min_element(pq.begin(), pq.end()));
    }
    return answer;
}

