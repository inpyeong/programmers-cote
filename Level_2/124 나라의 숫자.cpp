#include <string>
#include <vector>

using namespace std;
char ch[3] = { '1', '2', '4' };

string solution(int n) {
    --n;
    int a = n / 3, b = n % 3;
    if(a == 0) return string(1, ch[b]);
    string answer = solution(a) + string(1, ch[b]);
    return answer;
}
