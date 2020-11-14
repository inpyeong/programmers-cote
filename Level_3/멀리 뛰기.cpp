#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 2000, MOD = 1234567;
long long cache[MAX_N];

long long memoized(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    long long& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (memoized(n-2) % MOD + memoized(n-1) % MOD) % MOD;
}

long long solution(int n) {
    memset(cache, -1, sizeof(cache));
    long long answer = memoized(n);
    return answer;
}
