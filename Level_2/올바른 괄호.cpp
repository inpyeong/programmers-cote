#include <string>

using namespace std;

bool solution(string s)
{
    int tmp = 0;    
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '(') tmp++;
        else tmp--;
        if(tmp < 0) return false;
    }
    return tmp == 0;
}
