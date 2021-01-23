#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, pos = 0;
    while(true) {
        // 모두 바꿨다면 루프 종료
        if(name == string(name.length(), 'A')) break;
        // 'A'라면 바꿔야 할 알파벳의 위치탐색
        if(name[pos] == 'A') {
            int posL = pos, posR = pos;
            int cntL = 0, cntR = 0;
            while(name[posL] == 'A') {
                posL = (posL - 1) == -1 ? name.length() - 1 : posL - 1;
                cntL++;
            }
            while(name[posR] == 'A') {
                posR = (posR + 1) == name.length() ? 0 : posR + 1;
                cntR++;
            }
            if(cntL < cntR) {
                pos = posL;
                answer += cntL;
            }
            else {
                pos = posR;
                answer += cntR;
            }
        }
        else {
            int cntU = 'A' - name[pos];
            int cntD = 'Z' - name[pos] + 1;
            answer += min(abs(cntU), abs(cntD));
            name[pos] = 'A';
        }
    }
    return answer;
}
