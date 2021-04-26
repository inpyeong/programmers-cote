#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long answer;
vector<long long> num, _num;
vector<char> oper, _oper;

string allOper = "*+-";
bool check[3];

void getNumAndOper(string exp) {
    string tmp = "";
    for(int i = 0; i < exp.length(); ++i) {
        if(exp[i] == '*' || exp[i] == '+' || exp[i] == '-') {
            num.push_back(stoll(tmp));
            tmp = "";
            oper.push_back(exp[i]);
            continue;
        }
        tmp += exp[i];
        if(i == exp.length()-1)
            num.push_back(stoll(tmp));
    }
}

long long calc(char op, long long n1, long long n2) {
    if(op == '*') return n1*n2;
    if(op == '+') return n1+n2;
    if(op == '-') return n1-n2;
}

long long getResult(string myOper) {
    _num = num, _oper = oper;
    for(char op : myOper)
        for(int i = 0; i < _oper.size(); ++i) 
            if(_oper[i] == op) {
                long long tmp = calc(_oper[i], _num[i], _num[i+1]);
                _oper.erase(_oper.begin()+i);
                _num.erase(_num.begin()+i);
                _num.erase(_num.begin()+i);
                _num.insert(_num.begin()+i, tmp);
                i -= 1;
            }
    return _num.front();
}

void setPriority(int cnt, string myOper) {
    if(cnt == 3) {
        answer = max(answer, abs(getResult(myOper)));
        return;
    }
    for(int i = 0; i < 3; ++i) {
        if(check[i] == false) {
            check[i] = true;
            setPriority(cnt+1, myOper+allOper[i]);
            check[i] = false;
        }
    }
}

long long solution(string expression) {
    getNumAndOper(expression);
    setPriority(0, "");
    return answer;
}
