#include <string>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 1000000007;
int cache[600001];

int memoize(int w) {
    if(w == 1 || w == 0) return 1;

    int& ret = cache[w];
    if(ret != -1) return ret;

    return ret = (memoize(w - 1) % MAX + memoize(w - 2) % MAX) % MAX;
}

int solution(int n) {
    memset(cache, -1, sizeof(cache));
    cache[0] = cache[1] = 1;
    return memoize(n);
}
