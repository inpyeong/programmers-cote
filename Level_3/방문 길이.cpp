#include <string>
using namespace std;

// 이동했던 경로들을 기록하기 위해 구조체 배열 선언
struct Visit {
    bool U, D, R, L;
} map[11][11];

int solution(string dirs) {
    // 좌표가 인덱스로 들어가야함.
    // 음수 좌표를 없애주기 위해 현 위치를 (5, 5)로 변경
    int answer = 0, curX = 5, curY = 5;
    for(int i = 0; i < dirs.size(); ++i) {
        switch(dirs[i]) {
            case 'U':
                // 범위 넘어가면 무효
                if(curY == 10) break;
                // 한 번도 이동한 경로가 아니면
                if(!map[curY+1][curX].D) {
                    // 이동 경로 기록
                    map[curY][curX].U = true;
                    map[curY+1][curX].D = true;
                    answer++;
                }
                // 좌표 이동
                curY++;
                break;
            case 'D':
                if(curY == 0) break;
                if(!map[curY-1][curX].U) {
                    map[curY][curX].D = true;
                    map[curY-1][curX].U = true;
                    answer++;
                }
                curY--;
                break;
            case 'R':
                if(curX == 10) break;
                if(!map[curY][curX+1].L) {
                    map[curY][curX].R = true;
                    map[curY][curX+1].L = true;
                    answer++;
                }
                curX++;
                break;
            case 'L':
                if(curX == 0) break;
                if(!map[curY][curX-1].R) {
                    map[curY][curX].L = true;
                    map[curY][curX-1].R = true;
                    answer++;
                }
                curX--;
                break;
        }
    }
    return answer;
}
