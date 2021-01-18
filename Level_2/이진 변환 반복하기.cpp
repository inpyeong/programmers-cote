#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getBin(int one) {
    string ret = "";
    while(one > 0) {
        if(one % 2) ret += '1';
        else ret += '0';
        one/=2;
    }
    return ret;
}

vector<int> solution(string s) {
    int cnt = 0, del = 0;
    while(s.size() > 1) {
        cnt++;
        int one = 0;
        for(char c : s)
            if(c == '1') one++;
        int zero = s.size() - one;
        del += zero;
        s = getBin(one);
    }
    vector<int> answer = {cnt, del};
    return answer;
}
