#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = { 0, 0 };
    while(s != "1") {
        int cnt = 0;
        for(char c : s) {
            if(c == '1') cnt++;
            else answer[1]++;
        }
        s = "";
        while(cnt) {
            s += to_string(cnt % 2);
            cnt /= 2;
        }
        reverse(s.begin(), s.end());
        answer[0]++;
    }
    return answer;
}
