#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool midCheck(int mid, const vector<int>& stones, int k) {
    int cnt = 0;
    for(int i = 0; i < stones.size(); ++i) {
        if(stones[i] - mid <= 0) {
            cnt++;
            if(cnt >= k) return false;
        }
        else cnt = 0;
    }
    return true;
}

int binsearch(const vector<int>& stones, int k) {
    int lo = 0, hi = *max_element(stones.begin(), stones.end());
    while(lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if(midCheck(mid, stones, k)) 
            lo = mid;
        else
            hi = mid;
    }
    return hi;
}

int solution(vector<int> stones, int k) {
    int answer = binsearch(stones, k);
    return answer;
}
