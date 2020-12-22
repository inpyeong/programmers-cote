#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int quotient = s / n;
    int remainder = s % n;
    if(!quotient) return vector<int>(1, -1);
    for(int i = 0; i < n; ++i)
        answer.push_back(quotient);
    for(int i = 0; i < remainder; ++i)
        answer[i]++;
    sort(answer.begin(), answer.end());
    return answer;
}
