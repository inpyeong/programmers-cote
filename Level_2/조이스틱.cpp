#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, i = 0, length = name.length();
    string temp(length, 'A');
    while(true) {
        temp[i] = name[i];
        // 조이스틱을 위아래로 조작할 때 적게 조작할 수 있는 방향으로
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        // 조작이 완료되면 반복문 종료
        if(temp == name) break;
        // 오른쪽, 왼쪽 이동방향 결정
        for(int move = 1; move < length; ++move) {
            int rMove = (i + move) % length;
            int lMove = (i + length - move) % length;
            // 오른쪽 이동이 빠를 경우 
            if(name[rMove] != temp[rMove]) {
                i = rMove;
                answer += move;
                break;
            }
            // 왼쪽 이동이 빠를 경우
            else if(name[lMove] != temp[lMove]) {
                i = lMove;
                answer += move;
                break;
            }
        }
    }
    return answer;
}
