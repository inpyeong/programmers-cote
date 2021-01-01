#include <string>
#include <vector>

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
        answer = vector<int> { yh+2, yw+2 };
        return;
    }
    bruteForce(yw+1);
}

vector<int> solution(int brown, int yellow) {
    Brown = brown; 
    Yellow = yellow;
    bruteForce(1);
    return answer;
}
