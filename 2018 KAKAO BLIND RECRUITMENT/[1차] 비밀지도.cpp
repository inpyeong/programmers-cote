#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBin(int d, int n) {
    string ret = "";
    while(d > 0) {
        if(d % 2) ret += '#';
        else ret += '0';
        d /= 2;
    }
    reverse(ret.begin(), ret.end());
    while(ret.length() < n)
        ret = '0' + ret;
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; ++i) {
        string bin1 = getBin(arr1[i], n);
        string bin2 = getBin(arr2[i], n);
        string ans = "";
        for(int j = 0; j < n; ++j) {
            if(bin1[j] == '#' || bin2[j] == '#')
                ans += '#';
            else ans += ' ';
        }
        answer.push_back(ans);
    }
    return answer;
}
