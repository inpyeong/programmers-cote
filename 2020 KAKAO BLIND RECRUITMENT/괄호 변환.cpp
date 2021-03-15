#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isCorrect(string str) {
    int n = 0;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') n++;
        else n--;
        if(n < 0) return false;
    }
    if(n > 0) return false;
    return true;
}

string solution(string p) {
    if(p.size() == 0) return "";
    string u = "", v = "";
    int l = 0, r = 0;
    for(int i = 0; i < p.size(); ++i) {
    	if(p[i] == '(') l++;
        else r++;
        u += p[i];
        if(l == r) {
            v = p.substr(i+1);
            break;
        }
    }
    if(isCorrect(u)) {
        u += solution(v);
        return u;
    }
    else {
        string ans = "(";
        ans += solution(v);
        ans += ')';
        u = u.substr(1, u.size()-2);
        for(int j = 0; j < u.size(); ++j) {
            if(u[j] == '(') u[j] = ')';
            else u[j] = '(';
        }
        ans += u;
        return ans;
    }
}
