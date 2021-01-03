#include <string>
#include <vector>

using namespace std;

int N, T;

void dfs(const vector<int>& numbers, int& answer, int tmp, int cnt) {
    if(cnt == N) {
        if(tmp == T) answer++;
        return;
    }
    dfs(numbers, answer, tmp + numbers[cnt], cnt+1);
    dfs(numbers, answer, tmp - numbers[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    N = numbers.size();
    T = target;
    dfs(numbers, answer, 0, 0);
    return answer;
}
