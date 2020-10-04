#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int size = s.size();
    if(size % 2 == 0) return string(1, s[size/2-1]) + string(1, s[size/2]);
    else return string(1, s[size/2]);
}
