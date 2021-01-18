#include <iostream>
#include <vector>

using namespace std;

vector<int> sums;

bool isPrime(int n) {
    for(int i = 2; i*i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

void bruteForce(const vector<int>& nums, int idx, int cnt, int sum) {
    sum += nums[idx];
    for(int i = idx; i < nums.size(); ++i) {
        if(cnt == 2) {
            sums.push_back(sum);
            return;
        }
        else bruteForce(nums, i+1, cnt+1, sum);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 0; i < nums.size()-2; ++i)
        bruteForce(nums, i, 0, 0);
    for(int sum : sums)
        if(isPrime(sum)) answer++;
    return answer;
}
