#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> S;
    for(char c : s) {
        if(S.size() && S.top() == c) S.push(c);
        else S.pop();
    }
    return S.empty() ? 1 : 0;
}
