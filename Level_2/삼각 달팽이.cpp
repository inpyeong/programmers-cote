#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    // 달팽이 채우기 결과를 저장하는 2차원 배열
    int arr[1001][1001] = { 0, };
    int y = 0, x = 0, state = 0, num = 1;
    
    for(int i = 0; i < n; ++i) {
        switch(state) {
            // 왼쪽 아래로 진행
            case 0:
                for(int j = i; j < n; ++j)
                    arr[y++][x] = num++;
                y--;
                x++;
                state = 1;
                break;
            // 오른쪽으로 진행
            case 1:
                for(int j = i; j < n; ++j)
                    arr[y][x++] = num++;
                y--;
                x -= 2;
                state = 2;
                break;
            // 왼쪽 위로 진행
            case 2:
                for(int j = i; j < n; ++j)
                    arr[y--][x--] = num++;
                y += 2;
                x++;
                state = 0;
                break;
        }
    }
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j <= i; ++j)
            answer.push_back(arr[i][j]);
    return answer;
}
