#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // for(int i = 0; i < n; ++i) {
    //     int maxIdx = max_element(works.begin(), works.end()) - works.begin();
    //     if(works[maxIdx])
    //         works[maxIdx]--;
    // }
    
    sort(works.begin(), works.end(), cmp);
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        if(works[idx]) 
            works[idx]--;
        if(idx == works.size()-1) 
            idx = 0;
        if(works[idx] < works[idx+1]) 
            idx++;
        else idx = 0;
    }
    
    for(int i = 0; i < works.size(); ++i)
        answer += pow(works[i], 2);
    return answer;
}
