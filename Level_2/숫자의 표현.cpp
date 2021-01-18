#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        int tmp = i, total = 0;
        while(total <= n) {
            total += tmp;
            if(total == n) {
                answer++;
                break;
            }
            tmp++;
        }
    }
    return answer;
}
