#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int answer;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int sqrtn = int(sqrt(n));
    for(int div = 3; div <= sqrtn; div+=2)
        if(n % div == 0) 
            return false;
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
