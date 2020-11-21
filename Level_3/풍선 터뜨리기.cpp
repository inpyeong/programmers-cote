#include <vector>

using namespace std;

int solution(vector<int> a) {
    int aLength = a.size(), answer = 0;
    int lCache[aLength], rCache[aLength];
    lCache[0] = a[0], rCache[aLength-1] = a[aLength-1];
    for(int i = 1; i < aLength; ++i)
        lCache[i] = lCache[i-1] > a[i] ? a[i] : lCache[i-1];
    for(int i = aLength-2; i >= 0; --i)
        rCache[i] = rCache[i+1] > a[i] ? a[i] : rCache[i+1];
    for(int i = 0; i < aLength; ++i)
        if(a[i] <= lCache[i] || a[i] <= rCache[i]) answer++;
    return answer;
}
