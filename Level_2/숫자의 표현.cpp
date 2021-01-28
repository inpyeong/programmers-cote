#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i, sum = 0;; ++j) {
			sum += j;
            if(sum == n) answer++;
            if(sum > n) break;
        }
    return answer;
}
