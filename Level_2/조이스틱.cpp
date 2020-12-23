#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0, length = name.length();
    string temp(length, 'A');
    while(true) {
        temp[i] = name[i];
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        if(temp == name) break;
        for(int move = 1; move < length; ++move) {
            int rMove = (i + move) % length;
            int lMove = (i + length - move) % length;
            if(name[rMove] != temp[rMove]) {
                i = rMove;
                answer += move;
                break;
            }
            else if(name[lMove] != temp[lMove]) {
                i = lMove;
                answer += move;
                break;
            }
        }
    }
    return answer;
}
