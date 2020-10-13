#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    string s;
    do {
        int mod = n % 3;
        s += char('0' + mod);
        n /= 3;
    } while(n > 0);
    int answer = 0, pos = 0;
    for(int i = s.size()-1; i >= 0; --i) 
        answer += (s[pos++] - '0') * pow(3, i);
    return answer;
}
