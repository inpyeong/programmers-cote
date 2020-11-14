#include <string>
#include <vector>

using namespace std;

const int MAX_MONEY = 100, MAX_N = 100000, MOD = 1000000007;
int dp[MAX_N + 1];

int solution(int n, vector<int> money) {
    dp[0] = 1;
    for(auto m : money)
        for(int i = 0; i <= n; ++i) {
            if(i - m < 0) continue;
            dp[i] = (dp[i] + dp[i - m]) % MOD;
        }
    return dp[n] % MOD;
}
