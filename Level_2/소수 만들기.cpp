#include <vector>
#include <iostream>

using namespace std;

int answer;

bool isPrime(int n) {
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

void makePrime(const vector<int>& nums, int idx, int sum, int cnt) {
    sum += nums[idx];
    if(cnt == 3) {
        if(isPrime(sum)) answer++;
        return;
    }
    for(int i = idx+1; i < nums.size(); ++i)
        makePrime(nums, i, sum, cnt+1);
}

int solution(vector<int> nums) {
    for(int i = 0; i < nums.size(); ++i)
        makePrime(nums, i, 0, 1);
    return answer;
}
