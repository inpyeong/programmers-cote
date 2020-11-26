#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007, MAX_N = 100000;

int solution(int n, vector<int> money) {
    int dp[MAX_N+1] = { 0, };
    dp[0] = 1;
    for(auto m : money)
        for(int i = 0; i <= n; ++i)
            if(i >= m)
                dp[i] = (dp[i] + dp[i-m]) % MOD;
    return dp[n] % MOD;
}
