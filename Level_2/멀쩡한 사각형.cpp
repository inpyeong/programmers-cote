#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long solution(int w, int h) {
    long long answer = (long long)w * (long long)h - (w + h - gcd(w, h));
    return answer;
}
