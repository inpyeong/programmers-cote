#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> um;

bool isPrime(int n) {
    // 에라토스테네스의 체
    if(n == 0 || n == 1) return false;
    int k = (int)sqrt(n);
    for(int i = 2; i <= k; ++i)
        if(n % i == 0) return false;
    return true;
}

void bruteForce(string temp, string numbers, vector<bool>& used, int& answer) {
    if(temp.size()) {
        int tempNum = stoi(temp);
        if(isPrime(stoi(temp)) && !um[stoi(temp)]) {
            um[stoi(temp)] = true;
            answer++;
        }
    }
    for(int i = 0; i < numbers.size(); ++i) {
        if(used[i]) continue;
        used[i] = true;
        temp += numbers[i];
        bruteForce(temp, numbers, used, answer);
        temp = temp.substr(0, temp.size()-1);
        used[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> used(numbers.size(), false);
    bruteForce("", numbers, used, answer);
    return answer;
}
