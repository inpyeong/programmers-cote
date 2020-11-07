#include <string>
#include <vector>

using namespace std;

const int MAX_ANS = 8;
int gN, gNum;
int ans = MAX_ANS;

void dfs(int cnt, int curNum) {
    if(cnt > MAX_ANS) return;
    if(curNum == gNum)
        ans = min(ans, cnt);
    int tempNum = 0;
    for(int i = 0; i < MAX_ANS; ++i) {
        tempNum = tempNum * 10 + gN;
        dfs(cnt + 1 + i, curNum + tempNum);
        dfs(cnt + 1 + i, curNum - tempNum);
        dfs(cnt + 1 + i, curNum / tempNum);
        dfs(cnt + 1 + i, curNum * tempNum);
    }
}

int solution(int N, int number) {
    gN = N, gNum = number;
    dfs(0, 0);
    return ans <= MAX_ANS ? ans : -1;
}
