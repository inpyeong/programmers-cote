#include <iostream>

using namespace std;

long long solution(int a, int b) {
    int big = max(a, b), small = min(a, b);
    long long answer = 0;
    for(int i = small; i <= big; ++i) answer += i;
    return answer;
}
