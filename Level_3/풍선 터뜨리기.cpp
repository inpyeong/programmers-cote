#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int aSize = a.size();
    int leftCache[aSize], rightCache[aSize];
    leftCache[0] = a[0];
    for(int i = 1; i < aSize; ++i) {
        if(leftCache[i-1] > a[i]) leftCache[i] = a[i];
        else leftCache[i] = leftCache[i-1];
    }
    rightCache[aSize-1] = a[aSize-1];
    for(int i = aSize-2; i >= 0; --i) {
        if(rightCache[i+1] > a[i]) rightCache[i] = a[i];
        else rightCache[i] = rightCache[i+1];
    }
    int answer = 0;
    for(int i = 0; i < aSize; ++i)
        if(a[i] <= leftCache[i] || a[i] <= rightCache[i])
            answer++;
    return answer;
}
