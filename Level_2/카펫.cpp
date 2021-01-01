#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Brown, Yellow;
vector<int> answer;

void bruteForce(int yw) {
    if(Yellow % yw) {
        bruteForce(yw+1);
        return;
    }
    int yh = Yellow / yw;
    int cmp = (yw + yh) * 2 + 4;
    if(cmp == Brown) {
        answer = vector<int> { yw+2, yh+2 };
        return;
    }
    bruteForce(yw+1);
}

vector<int> solution(int brown, int yellow) {
    Brown = brown; 
    Yellow = yellow;
    bruteForce(1);
    if(answer[0] < answer[1]) 
        swap(answer[0], answer[1]);
    return answer;
}
