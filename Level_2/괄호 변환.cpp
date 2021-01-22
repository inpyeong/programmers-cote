#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string str, int* pos) {
    bool ret = true;
    int left = 0, right = 0;
    stack<char> mystack;
    
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == '(') {
            left++;
            mystack.push('(');
        }
        else {
            right++;
            if(mystack.empty()) ret = false;
            else mystack.pop();
        }
        if(left == right) {
            *pos = i + 1;
            return ret;
        }
    }
    return true;
}

string solution(string p) {
    if(p.empty()) return p;
    
    int pos;
    bool correct = isCorrect(p, &pos);
    string u = p.substr(0, pos);
    string v = p.substr(pos);
    
    if(correct) return u + solution(v);
    
    string answer = "(" + solution(v) + ')';
    for(int i = 1; i < u.length() - 1; ++i) {
        if(u[i] == '(') answer += ")";
        else answer += "(";
    }
    return answer;
}
