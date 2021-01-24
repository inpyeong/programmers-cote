#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(const vector<int>& numbers, int target, int idx, int tmp) {
    if(idx == numbers.size()) {
        if(tmp == target) answer++;
        return;
    }
    dfs(numbers, target, idx+1, tmp - numbers[idx]);
    dfs(numbers, target, idx+1, tmp + numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
