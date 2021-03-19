#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length()/2; ++i) {
        int pos = 0;
        int len = s.length();
        while(true) {
            string unit = s.substr(pos, i);
            pos += i;
            if(pos >= s.length()) break;
            int cnt = 0;
            while(true) {
                if(unit.compare(s.substr(pos, i)) == 0) {
					cnt++;
                    pos += i;
                } 
                else break;
            }
            if(cnt > 0) {
                len -= (i * cnt);
                if(cnt < 9) len += 1;
                else if(cnt < 99) len += 2;
                else if(cnt < 999) len += 3;
                else len += 4;
            }
        }
        answer = min(answer, len);
    }
    return answer;
}
