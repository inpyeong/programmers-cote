#include <cstring>
#include <vector>

using namespace std;

const int MOD = 1234567;
int cache[100001];

int F(int n) {
    if(n <= 1) return n;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (F(n-1) + F(n-2)) % MOD;
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    return F(n);
}
