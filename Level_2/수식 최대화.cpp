#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long cal(long long a, long long b, char op) {
    switch(op) {
        case '*':
            return a * b;
        case '+':
            return a + b;
        case '-':
            return a - b;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> opers;
    vector<long long> nums;
    string num = "";
    for(char c : expression) {
        if(c == '-' || c == '+' || c == '*') {
            nums.push_back(stoll(num));
            num.clear();
            opers.push_back(c);
        }
        else num += c;
    }
    nums.push_back(stoll(num));
    string oper = "*+-";
    do {
        vector<char> tmpOpers = opers;
        vector<long long> tmpNums = nums;
        for(char op : oper) {
            for(int i = 0; i < tmpOpers.size(); ++i) {
                long long ret = 0;
                if(tmpOpers[i] == op) {
                    ret += cal(tmpNums[i], tmpNums[i+1], tmpOpers[i]);
                    tmpNums[i] = ret;
                    tmpOpers.erase(tmpOpers.begin() + i);
                    tmpNums.erase(tmpNums.begin() + i + 1);
                    i--;
                }
            }
        }
        answer = max(answer, abs(tmpNums[0]));
    } while(next_permutation(oper.begin(), oper.end()));
    
    return answer;
}
