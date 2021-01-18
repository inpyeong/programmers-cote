#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> S;
    for(char c : s) {
        if(S.empty() || S.top() != c) 
            S.push(c);
        else
            if(S.top() == c) S.pop();
    }
    return S.empty() ? 1 : 0;
}
