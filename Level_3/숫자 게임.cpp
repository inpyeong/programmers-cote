#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int win = 0, aIdx = 0, bIdx = 0;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    // 애초에 승점을 얻을 수 없는 경우
    if(A[A.size()-1] >= B[bIdx]) return 0;
    for(int i = 0; i < A.size(); ++i) {
        // 승점을 얻는 경우
        if(A[i] < B[bIdx]) {
            bIdx++;
            win++;
        }
        aIdx++;
    }
    return win;
}
