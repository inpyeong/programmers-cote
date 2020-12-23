#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int> >& answer, int n, int from, int to, int tmp) {
    vector<int> temp = { from, to };
    if(n == 1) answer.push_back(temp);
    else {
        hanoi(answer, n-1, from, tmp, to);
        answer.push_back(temp);
        hanoi(answer, n-1, tmp, to, from);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 3, 2);
    return answer;
}
