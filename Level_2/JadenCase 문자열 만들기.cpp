#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for(int i = 0; i < s.size(); ++i) {
        // 공백은 통과
        if(s[i] == ' ') continue;
        // 문장의 첫 문자이거나 각 단어의 첫 문자인 경우 소문자를 대문자로 변경
        if(i == 0 || (i > 0 && s[i-1] == ' ')) {
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
        // 그 외 모든 소문자를 대문자로 변경
        else {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
    return s;
}
