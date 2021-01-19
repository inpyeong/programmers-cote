#include <iostream>

using namespace std;

bool fight(int a, int b) {
    if(abs(a-b) > 1) return false;
    // 큰 수가 짝수가 아니면 붙지 않음
    int big = max(a, b);
    if(big % 2 == 1) return false;
    return true;
}

int getNextNum(int a) {
    int ret = a / 2;
    if(a % 2 == 0) return ret;
    else return ret + 1;
}

int solution(int n, int a, int b) {
    int answer = 1;
    while(!fight(a, b)) {
        a = getNextNum(a);
        b = getNextNum(b);
        answer++;
    }
    return answer;
}
