#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i = 0, idx = -1; i < number.size()-k; ++i) {
        char max = 0;
        for(int j = idx+1; j <= k+i; ++j) {
            if(number[j] > max) {
                max = number[j];
                idx = j;
            }
        }
        answer += max;
    }
    return answer;
}
