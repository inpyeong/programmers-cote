#include <string>
#include <vector>

using namespace std;

const int MAX_N = 12;
int col[MAX_N];
int N, answer;

bool check(int level) {
    for(int i = 0; i < level; ++i) 
        // 같은 열에 있거나 대각선에 위치하는 경우,
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void queen(int x) {
    if(x == N) answer++;
    else {
        for(int i = 0; i < N; ++i) {
            col[x] = i;
            if(check(x)) 
                queen(x+1);
        }
    }
}

int solution(int n) {
    N = n;
    queen(0);
    return answer;
}
