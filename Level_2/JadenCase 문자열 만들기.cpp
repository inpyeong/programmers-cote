#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
    for(int i = 1; i < s.length(); ++i) 
        if(s[i-1] == ' ' && s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    return s;
}
