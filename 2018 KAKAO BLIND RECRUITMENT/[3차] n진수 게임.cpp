#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string ans = "0";
    for(int i = 1; ; ++i) {
        string a = "";
        int num = i;
        while(num) {
            int remainder = num % n;
            if(remainder < 10) 
                a += ('0' + remainder);
            else {
                remainder -= 10;
                a += ('A' + remainder);
            }
            num /= n;
        }
        reverse(a.begin(), a.end());
        ans += a;
        if(ans.size() >= t * m) break;
    }
    for(int i = 0; i < ans.size(); ++i)
        if(i % m == p - 1) {
            answer += ans[i];
            if(answer.size() == t)
                break;
        }
    return answer;
}
