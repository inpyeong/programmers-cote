#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	  stack<char> S;
    for(char c : s) {
        if(c == '(' || S.empty())
            S.push(c);
        else {
            if(S.top() == '(') S.pop();
            else S.push(c);
        }
    }
	  bool answer = S.size() ? false : true;
    return answer;
}
